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

#ifndef __JUCE_HEADER_F1FF5EEF8E95917A__
#define __JUCE_HEADER_F1FF5EEF8E95917A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"

#include <ctime>

#include "auxilliary/logger.h"
#include "auxilliary/juce_file_io.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class waveform_component  : public Component,
                            public FileDragAndDropTarget
{
public:
    //==============================================================================
    waveform_component ();
    ~waveform_component();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	bool isInterestedInFileDrag (const StringArray& files);
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
    bool keyPressed (const KeyPress& key);
    bool keyStateChanged (const bool isKeyDown);
    void modifierKeysChanged (const ModifierKeys& modifiers);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	aux::logger* logger;
	aux::logger_params* logger_params;

	CriticalSection audio_data_lock;
	float* audio_data;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (waveform_component)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_F1FF5EEF8E95917A__
