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

#include "imaphone_component.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
imaphone_component::imaphone_component ()
{
    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("imaphone")));
    label->setFont (Font (24.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colour (0xff4f58c9));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("image")));

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             TRANS("waveform")));

    addAndMakeVisible (component = new image_component());
    component->setName ("new component");

    addAndMakeVisible (component2 = new waveform_component());
    component2->setName ("new component");

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (TRANS("row"));
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("row"), 1);
    comboBox->addItem (TRANS("column"), 2);
    comboBox->addItem (TRANS("spiral"), 3);
    comboBox->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("scan pattern")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (toggleButton = new ToggleButton ("new toggle button"));
    toggleButton->setButtonText (TRANS("r"));
    toggleButton->addListener (this);

    addAndMakeVisible (toggleButton2 = new ToggleButton ("new toggle button"));
    toggleButton2->setButtonText (TRANS("g"));
    toggleButton2->addListener (this);

    addAndMakeVisible (toggleButton3 = new ToggleButton ("new toggle button"));
    toggleButton3->setButtonText (TRANS("b"));
    toggleButton3->addListener (this);

    addAndMakeVisible (toggleButton4 = new ToggleButton ("new toggle button"));
    toggleButton4->setButtonText (TRANS("gs"));
    toggleButton4->addListener (this);

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("->"));
    textButton->addListener (this);

    addAndMakeVisible (textButton2 = new TextButton ("new button"));
    textButton2->setButtonText (TRANS("<-"));
    textButton2->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

imaphone_component::~imaphone_component()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    groupComponent = nullptr;
    groupComponent2 = nullptr;
    component = nullptr;
    component2 = nullptr;
    comboBox = nullptr;
    label2 = nullptr;
    toggleButton = nullptr;
    toggleButton2 = nullptr;
    toggleButton3 = nullptr;
    toggleButton4 = nullptr;
    textButton = nullptr;
    textButton2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void imaphone_component::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::whitesmoke);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void imaphone_component::resized()
{
    label->setBounds (8, 8, 112, 32);
    groupComponent->setBounds (8, 32, 264, 368);
    groupComponent2->setBounds (328, 32, 264, 368);
    component->setBounds (16, 48, 248, 248);
    component2->setBounds (336, 48, 248, 248);
    comboBox->setBounds (112, 304, 150, 24);
    label2->setBounds (16, 304, 80, 24);
    toggleButton->setBounds (24, 336, 32, 24);
    toggleButton2->setBounds (64, 336, 32, 24);
    toggleButton3->setBounds (104, 336, 32, 24);
    toggleButton4->setBounds (144, 336, 40, 24);
    textButton->setBounds (272, 144, 55, 24);
    textButton2->setBounds (272, 176, 55, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void imaphone_component::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void imaphone_component::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
        //[/UserButtonCode_toggleButton]
    }
    else if (buttonThatWasClicked == toggleButton2)
    {
        //[UserButtonCode_toggleButton2] -- add your button handler code here..
        //[/UserButtonCode_toggleButton2]
    }
    else if (buttonThatWasClicked == toggleButton3)
    {
        //[UserButtonCode_toggleButton3] -- add your button handler code here..
        //[/UserButtonCode_toggleButton3]
    }
    else if (buttonThatWasClicked == toggleButton4)
    {
        //[UserButtonCode_toggleButton4] -- add your button handler code here..
        //[/UserButtonCode_toggleButton4]
    }
    else if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="imaphone_component" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="fff5f5f5"/>
  <LABEL name="new label" id="e8473a24522c9b8f" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 8 112 32" textCol="ff4f58c9" edTextCol="ff000000"
         edBkgCol="0" labelText="imaphone" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="24"
         bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="new group" id="9be532293b503154" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 32 264 368" title="image"/>
  <GROUPCOMPONENT name="new group" id="f0cb1b564ec62f53" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="328 32 264 368" title="waveform"/>
  <GENERICCOMPONENT name="new component" id="47ed444cbfc17b76" memberName="component"
                    virtualName="" explicitFocusOrder="0" pos="16 48 248 248" class="image_component"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="488d7df3e5aa6c5" memberName="component2"
                    virtualName="" explicitFocusOrder="0" pos="336 48 248 248" class="waveform_component"
                    params=""/>
  <COMBOBOX name="new combo box" id="43e8bee5de81e80" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="112 304 150 24" editable="0"
            layout="33" items="row&#10;column&#10;spiral" textWhenNonSelected="row"
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="33ef735ddc98c1e" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="16 304 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="scan pattern" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="c68317834d28f2f9" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="24 336 32 24" buttonText="r"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="fa97bc69cb5f2157" memberName="toggleButton2"
                virtualName="" explicitFocusOrder="0" pos="64 336 32 24" buttonText="g"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="8a97afda47542016" memberName="toggleButton3"
                virtualName="" explicitFocusOrder="0" pos="104 336 32 24" buttonText="b"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="e26c5493a23d1c34" memberName="toggleButton4"
                virtualName="" explicitFocusOrder="0" pos="144 336 40 24" buttonText="gs"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="new button" id="75dc2166e80c51c9" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="272 144 55 24" buttonText="-&gt;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="4713648ba57ab77f" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="272 176 55 24" buttonText="&lt;-"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
