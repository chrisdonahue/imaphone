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

#include "WaveformComponent.h"

#include "image_component.h"
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
    void mouseDown (const MouseEvent& e);
    void mouseUp (const MouseEvent& e);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::vector<ToggleButton*>* color_radios;

	void color_radios_clear(ToggleButton* exclude);

	AudioTransportSource transportSource;
	ScopedPointer<WaveformComponent> waveform;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> label;
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<GroupComponent> groupComponent2;
    ScopedPointer<image_component> image;
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<Label> label2;
    ScopedPointer<ToggleButton> color_radio_red;
    ScopedPointer<ToggleButton> color_radio_green;
    ScopedPointer<ToggleButton> color_radio_blue;
    ScopedPointer<ToggleButton> color_radio_greyscale;
    ScopedPointer<TextButton> textButton;
    ScopedPointer<TextButton> textButton2;
    ScopedPointer<TextButton> color_preview;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (imaphone_component)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_EAD602C4CAC42026__
