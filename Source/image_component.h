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

#ifndef __JUCE_HEADER_75FEAFCD384A25FE__
#define __JUCE_HEADER_75FEAFCD384A25FE__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"

enum color_signal;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class image_component  : public Component,
                         public FileDragAndDropTarget
{
public:
    //==============================================================================
    image_component ();
    ~image_component();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	bool isInterestedInFileDrag (const StringArray& files);

	enum color_signal {red, green, blue, greyscale};
	void set_color_full_preview(bool preview);
	void set_color_signal(color_signal color);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void filesDropped (const StringArray& filenames, int mouseX, int mouseY);
    void mouseMove (const MouseEvent& e);
    void mouseEnter (const MouseEvent& e);
    void mouseExit (const MouseEvent& e);
    void mouseDown (const MouseEvent& e);
    void mouseDrag (const MouseEvent& e);
    void mouseUp (const MouseEvent& e);
    void mouseDoubleClick (const MouseEvent& e);
    void mouseWheelMove (const MouseEvent& e, const MouseWheelDetails& wheel);
    void modifierKeysChanged (const ModifierKeys& modifiers);

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	CriticalSection image_lock;
	Image image;
	Image image_red;
	Image image_green;
	Image image_blue;
	Image image_greyscale;

	color_signal color_current;
	bool color_full_preview;

	void process_image();
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (image_component)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_75FEAFCD384A25FE__
