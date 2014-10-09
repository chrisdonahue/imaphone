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

#ifndef __JUCE_HEADER_EAD602C4CAC42026__
#define __JUCE_HEADER_EAD602C4CAC42026__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"

#include "image_component.h"
#include "waveform_component.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class imaphone_component  : public Component,
                            public ComboBoxListener,
                            public ButtonListener
{
public:
    //==============================================================================
    imaphone_component ();
    ~imaphone_component();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* fa_arrow_right_svg;
    static const int fa_arrow_right_svgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> label;
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<GroupComponent> groupComponent2;
    ScopedPointer<image_component> component;
    ScopedPointer<waveform_component> component2;
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<Label> label2;
    ScopedPointer<ToggleButton> toggleButton;
    ScopedPointer<ToggleButton> toggleButton2;
    ScopedPointer<ToggleButton> toggleButton3;
    ScopedPointer<ToggleButton> toggleButton4;
    ScopedPointer<TextButton> textButton;
    ScopedPointer<TextButton> textButton2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (imaphone_component)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_EAD602C4CAC42026__
