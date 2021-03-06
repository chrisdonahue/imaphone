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

#include "image_component.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
image_component::image_component ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (496, 240);


    //[Constructor] You can add your own custom stuff here..
	color_full_preview = false;
    //[/Constructor]
}

image_component::~image_component()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void image_component::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff222222));

    //[UserPaint] Add your own custom painting code here..
	const ScopedLock sl (image_lock);

	Image* current = &image;
	switch (color_current) {
	case color_signal::red:
		current = &image_red;
		break;
	case color_signal::green:
		current = &image_green;
		break;
	case color_signal::blue:
		current = &image_blue;
		break;
	case color_signal::greyscale:
		current = &image_greyscale;
		break;
	default:
		current = &image;
	}
	if (color_full_preview) {
		current = &image;
	}
	g.drawImageWithin(*current, 0, 0, this->getWidth(), this->getHeight(), RectanglePlacement::centred);
    //[/UserPaint]
}

void image_component::resized()
{
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void image_component::filesDropped (const StringArray& filenames, int mouseX, int mouseY)
{
    //[UserCode_filesDropped] -- Add your code here...
	const ScopedLock sl (image_lock);
	const File& dropped_file(filenames[0]);
	image = ImageFileFormat::loadFrom(dropped_file);
	process_image();
	repaint();
    //[/UserCode_filesDropped]
}

void image_component::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
    //[/UserCode_mouseMove]
}

void image_component::mouseEnter (const MouseEvent& e)
{
    //[UserCode_mouseEnter] -- Add your code here...
    //[/UserCode_mouseEnter]
}

void image_component::mouseExit (const MouseEvent& e)
{
    //[UserCode_mouseExit] -- Add your code here...
    //[/UserCode_mouseExit]
}

void image_component::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    //[/UserCode_mouseDown]
}

void image_component::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    //[/UserCode_mouseDrag]
}

void image_component::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    //[/UserCode_mouseUp]
}

void image_component::mouseDoubleClick (const MouseEvent& e)
{
    //[UserCode_mouseDoubleClick] -- Add your code here...
    //[/UserCode_mouseDoubleClick]
}

void image_component::mouseWheelMove (const MouseEvent& e, const MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...
    //[/UserCode_mouseWheelMove]
}

void image_component::modifierKeysChanged (const ModifierKeys& modifiers)
{
    //[UserCode_modifierKeysChanged] -- Add your code here...
    //[/UserCode_modifierKeysChanged]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void image_component::set_color_full_preview(bool preview) {
	color_full_preview = preview;
	repaint();
}

void image_component::set_color_signal(color_signal color) {
	color_current = color;
	repaint();
}

void image_component::process_image() {
	image_red = image.createCopy();
	image_green = image.createCopy();
	image_blue = image.createCopy();
	image_greyscale = image.createCopy();
	int width = image.getWidth();
	int height = image.getHeight();

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < width; y++) {
			Colour pixel_current = image.getPixelAt(x, y);
			uint8 red = pixel_current.getRed();
			uint8 green = pixel_current.getGreen();
			uint8 blue = pixel_current.getBlue();
			uint8 alpha = pixel_current.getAlpha();
			uint8 average = (uint8) (float(red + green + blue) / 3.0f);
			image_red.setPixelAt(x, y, Colour(red, 0, 0, alpha));
			image_green.setPixelAt(x, y, Colour(0, green, 0, alpha));
			image_blue.setPixelAt(x, y, Colour(0, 0, blue, alpha));
			image_greyscale.setPixelAt(x, y, Colour(average, average, average, alpha));
		}
	}
}

bool image_component::isInterestedInFileDrag (const StringArray& files)
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

<JUCER_COMPONENT documentType="Component" className="image_component" componentName=""
                 parentClasses="public Component, public FileDragAndDropTarget"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="496"
                 initialHeight="240">
  <METHODS>
    <METHOD name="filesDropped (const StringArray&amp; filenames, int mouseX, int mouseY)"/>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
    <METHOD name="mouseEnter (const MouseEvent&amp; e)"/>
    <METHOD name="mouseExit (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDoubleClick (const MouseEvent&amp; e)"/>
    <METHOD name="mouseWheelMove (const MouseEvent&amp; e, const MouseWheelDetails&amp; wheel)"/>
    <METHOD name="modifierKeysChanged (const ModifierKeys&amp; modifiers)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff222222"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
