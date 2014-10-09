/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "waveform_component.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
waveform_component::waveform_component ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (496, 240);


    //[Constructor] You can add your own custom stuff here..
	// initialize logger
	logger_params = (aux::logger_params*) malloc(sizeof(aux::logger_params));
	logger_params->log_params = (aux::log_params*) malloc(sizeof(aux::log_params));
	logger_params->verbose_params = (aux::log_params*) malloc(sizeof(aux::log_params));
	logger_params->debug_params = (aux::log_params*) malloc(sizeof(aux::log_params));
	logger_params->error_params = (aux::log_params*) malloc(sizeof(aux::log_params));

	logger_params->log_params->to_file = true;
	logger_params->log_params->to_cout = false;
	logger_params->log_params->to_cerr = false;
	logger_params->verbose_params->to_file = true;
	logger_params->verbose_params->to_cout = false;
	logger_params->verbose_params->to_cerr = false;
	logger_params->debug_params->to_file = true;
	logger_params->debug_params->to_cout = false;
	logger_params->debug_params->to_cerr = false;
	logger_params->error_params->to_file = true;
	logger_params->error_params->to_cout = false;
	logger_params->error_params->to_cerr = false;

	logger_params->log_precision = 4;
	logger_params->verbose_to_log = true;

	time_t rawtime;
	struct tm * timeinfo;
	char time_string[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(time_string, 80, "%Y.%m.%d.%I.%M.%S", timeinfo);
	std::string str(time_string);

	logger = new aux::logger(logger_params, time_string, "C:\\Code\\autosample\\debug\\");

	// init audio buffer
	audio_data = nullptr;
    //[/Constructor]
}

waveform_component::~waveform_component()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..

	// delete logger
	free(logger_params->log_params);
    free(logger_params->verbose_params);
    free(logger_params->debug_params);
    free(logger_params->error_params);
    free(logger_params);
	delete logger;

	free(audio_data);

    //[/Destructor]
}

//==============================================================================
void waveform_component::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
	if (audio_data == nullptr) {
		return;
	}
	const ScopedLock sl (audio_data_lock);
	g.setColour(Colours::blue);
	int width = this->getWidth();
	int height = this->getHeight();
	for (int x = 0; x < this->getWidth() - 1; x++) {
		float frame = audio_data[x];
		int y = (120 * frame) + 120;
		int y_prime = (120 * audio_data[x + 1]) + 120;
		g.drawLine((float) x, (float) y, (float) x + 1, (float) y_prime);
	}
	g.setColour(Colours::red);
	g.drawLine(0.0f, 120.0f, 490.0f, 120.0f);
    //[/UserPaint]
}

void waveform_component::resized()
{
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void waveform_component::filesDropped (const StringArray& filenames, int mouseX, int mouseY)
{
    //[UserCode_filesDropped] -- Add your code here...
	const ScopedLock sl (audio_data_lock);
	String filename = filenames[0];
	unsigned long num_frames;
	unsigned bits_per_sample;
	double length_seconds;
	double sampling_frequency;
	double nyquist_frequency;
	aux::juce_file_io::get_wav_file_metadata(filename.toStdString(), &num_frames, &bits_per_sample, &length_seconds, &sampling_frequency, &nyquist_frequency);
	free(audio_data);
	audio_data = (float*) malloc(sizeof(float) * num_frames);
	aux::juce_file_io::load_wav_file(filename.toStdString(), 256, num_frames, audio_data);
	this->repaint();
    //[/UserCode_filesDropped]
}

void waveform_component::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
    //[/UserCode_mouseMove]
}

void waveform_component::mouseEnter (const MouseEvent& e)
{
    //[UserCode_mouseEnter] -- Add your code here...
    //[/UserCode_mouseEnter]
}

void waveform_component::mouseExit (const MouseEvent& e)
{
    //[UserCode_mouseExit] -- Add your code here...
    //[/UserCode_mouseExit]
}

void waveform_component::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    //[/UserCode_mouseDown]
}

void waveform_component::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    //[/UserCode_mouseDrag]
}

void waveform_component::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    //[/UserCode_mouseUp]
}

void waveform_component::mouseDoubleClick (const MouseEvent& e)
{
    //[UserCode_mouseDoubleClick] -- Add your code here...
    //[/UserCode_mouseDoubleClick]
}

void waveform_component::mouseWheelMove (const MouseEvent& e, const MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...
    //[/UserCode_mouseWheelMove]
}

bool waveform_component::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}

bool waveform_component::keyStateChanged (const bool isKeyDown)
{
    //[UserCode_keyStateChanged] -- Add your code here...
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyStateChanged]
}

void waveform_component::modifierKeysChanged (const ModifierKeys& modifiers)
{
    //[UserCode_modifierKeysChanged] -- Add your code here...
    //[/UserCode_modifierKeysChanged]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
bool waveform_component::isInterestedInFileDrag (const StringArray& files)
{
	return files.size() == 1;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="waveform_component" componentName=""
                 parentClasses="public Component, public FileDragAndDropTarget"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="496"
                 initialHeight="240">
  <METHODS>
    <METHOD name="filesDropped (const StringArray&amp; filenames, int mouseX, int mouseY)"/>
    <METHOD name="modifierKeysChanged (const ModifierKeys&amp; modifiers)"/>
    <METHOD name="keyStateChanged (const bool isKeyDown)"/>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
    <METHOD name="mouseWheelMove (const MouseEvent&amp; e, const MouseWheelDetails&amp; wheel)"/>
    <METHOD name="mouseDoubleClick (const MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseExit (const MouseEvent&amp; e)"/>
    <METHOD name="mouseEnter (const MouseEvent&amp; e)"/>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
