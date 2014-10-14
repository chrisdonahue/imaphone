/*
  ==============================================================================

    WaveformComponent.cpp
    Created: 13 Oct 2014 5:12:17pm
    Author:  Chris

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "WaveformComponent.h"

//==============================================================================
WaveformComponent::WaveformComponent (AudioTransportSource& transportSource_)
	:   transportSource(transportSource_),
		thread("audio file preview"),
		scrollbar (false),
		formatManager(),
        thumbnailCache (5),
        thumbnail (512, formatManager, thumbnailCache),
        isFollowingTransport (false)
{
    thumbnail.addChangeListener (this);

    addAndMakeVisible (scrollbar);
    scrollbar.setRangeLimits (visibleRange);
    scrollbar.setAutoHide (false);
    scrollbar.addListener (this);

    currentPositionMarker.setFill (Colours::white.withAlpha (0.85f));
    addAndMakeVisible (currentPositionMarker);

    formatManager.registerBasicFormats();
}

WaveformComponent::~WaveformComponent()
{
    scrollbar.removeListener (this);
    thumbnail.removeChangeListener (this);
}

void WaveformComponent::setFile (const File& file)
{
    if (! file.isDirectory())
    {
        thumbnail.setSource (new FileInputSource (file));
        const Range<double> newRange (0.0, thumbnail.getTotalLength());
        scrollbar.setRangeLimits (newRange);
        setRange (newRange);

        startTimer (1000 / 40);
    }
}

File WaveformComponent::getLastDroppedFile() const noexcept
{
	return lastFileDropped;
}

void WaveformComponent::setZoomFactor (double amount)
{
    if (thumbnail.getTotalLength() > 0)
    {
        const double newScale = jmax (0.001, thumbnail.getTotalLength() * (1.0 - jlimit (0.0, 0.99, amount)));
        const double timeAtCentre = xToTime (getWidth() / 2.0f);
        setRange (Range<double> (timeAtCentre - newScale * 0.5, timeAtCentre + newScale * 0.5));
    }
}

void WaveformComponent::setRange (Range<double> newRange)
{
    visibleRange = newRange;
    scrollbar.setCurrentRange (visibleRange);
    updateCursorPosition();
    repaint();
}

void WaveformComponent::setFollowsTransport (bool shouldFollow)
{
    isFollowingTransport = shouldFollow;
}

void WaveformComponent::paint (Graphics& g)
{
    g.fillAll (Colours::darkgrey);
    g.setColour (Colours::lightblue);

    if (thumbnail.getTotalLength() > 0.0)
    {
        Rectangle<int> thumbArea (getLocalBounds());
        thumbArea.removeFromBottom (scrollbar.getHeight() + 4);
        thumbnail.drawChannels (g, thumbArea.reduced (2),
                                visibleRange.getStart(), visibleRange.getEnd(), 1.0f);
    }
    else
    {
        g.setFont (14.0f);
        g.drawFittedText ("(No audio file selected)", getLocalBounds(), Justification::centred, 2);
    }
}

void WaveformComponent::resized()
{
    scrollbar.setBounds (getLocalBounds().removeFromBottom (14).reduced (2));
}

void WaveformComponent::changeListenerCallback (ChangeBroadcaster*)
{
    // this method is called by the thumbnail when it has changed, so we should repaint it..
    repaint();
}

bool WaveformComponent::isInterestedInFileDrag (const StringArray& /*files*/)
{
    return true;
}

void WaveformComponent::filesDropped (const StringArray& files, int /*x*/, int /*y*/)
{
    lastFileDropped = File (files[0]);
	const File& audioFile = lastFileDropped;

    // unload the previous file source and delete it..
    transportSource.stop();
    transportSource.setSource (nullptr);
    currentAudioFileSource = nullptr;

    AudioFormatReader* reader = formatManager.createReaderFor (audioFile);

    if (reader != nullptr)
    {
        currentAudioFileSource = new AudioFormatReaderSource (reader, true);

        // ..and plug it into our transport source
        transportSource.setSource (currentAudioFileSource,
                                    32768,                   // tells it to buffer this many samples ahead
                                    &thread,                 // this is the background thread to use for reading-ahead
                                    reader->sampleRate);     // allows for sample rate correction
    }

    //zoomSlider.setValue (0, dontSendNotification);
	const File& file = audioFile;
    setFile (file);
}

void WaveformComponent::mouseDown (const MouseEvent& e)
{
    mouseDrag (e);
}

void WaveformComponent::mouseDrag (const MouseEvent& e)
{
    if (canMoveTransport())
        transportSource.setPosition (jmax (0.0, xToTime ((float) e.x)));
}

void WaveformComponent::mouseUp (const MouseEvent&)
{
    transportSource.start();
}

void WaveformComponent::mouseWheelMove (const MouseEvent&, const MouseWheelDetails& wheel)
{
    if (thumbnail.getTotalLength() > 0.0)
    {
        double newStart = visibleRange.getStart() - wheel.deltaX * (visibleRange.getLength()) / 10.0;
        newStart = jlimit (0.0, jmax (0.0, thumbnail.getTotalLength() - (visibleRange.getLength())), newStart);

        if (canMoveTransport())
            setRange (Range<double> (newStart, newStart + visibleRange.getLength()));

		/*
        if (wheel.deltaY != 0.0f)
            zoomSlider.setValue (zoomSlider.getValue() - wheel.deltaY);
		*/

        repaint();
    }
}

float WaveformComponent::timeToX (const double time) const
{
    return getWidth() * (float) ((time - visibleRange.getStart()) / (visibleRange.getLength()));
}

double WaveformComponent::xToTime (const float x) const
{
    return (x / getWidth()) * (visibleRange.getLength()) + visibleRange.getStart();
}

bool WaveformComponent::canMoveTransport() const noexcept
{
    return ! (isFollowingTransport && transportSource.isPlaying());
}

void WaveformComponent::scrollBarMoved (ScrollBar* scrollBarThatHasMoved, double newRangeStart)
{
    if (scrollBarThatHasMoved == &scrollbar)
        if (! (isFollowingTransport && transportSource.isPlaying()))
            setRange (visibleRange.movedToStartAt (newRangeStart));
}

void WaveformComponent::timerCallback()
{
    if (canMoveTransport())
        updateCursorPosition();
    else
        setRange (visibleRange.movedToStartAt (transportSource.getCurrentPosition() - (visibleRange.getLength() / 2.0)));
}

void WaveformComponent::updateCursorPosition()
{
    currentPositionMarker.setVisible (transportSource.isPlaying() || isMouseButtonDown());

    currentPositionMarker.setRectangle (Rectangle<float> (timeToX (transportSource.getCurrentPosition()) - 0.75f, 0,
                                                            1.5f, (float) (getHeight() - scrollbar.getHeight())));
}