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

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: fa_arrow_right_svg, 1966, "../assets/fa_arrow_right.svg"
static const unsigned char resource_imaphone_component_fa_arrow_right_svg[] = { 60,63,120,109,108,32,118,101,114,115,105,111,110,61,34,49,46,48,34,32,101,110,99,111,100,105,110,103,61,34,85,84,70,45,56,
34,32,115,116,97,110,100,97,108,111,110,101,61,34,110,111,34,63,62,10,60,115,118,103,10,32,32,32,120,109,108,110,115,58,100,99,61,34,104,116,116,112,58,47,47,112,117,114,108,46,111,114,103,47,100,99,47,
101,108,101,109,101,110,116,115,47,49,46,49,47,34,10,32,32,32,120,109,108,110,115,58,99,99,61,34,104,116,116,112,58,47,47,99,114,101,97,116,105,118,101,99,111,109,109,111,110,115,46,111,114,103,47,110,
115,35,34,10,32,32,32,120,109,108,110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,
110,115,35,34,10,32,32,32,120,109,108,110,115,58,115,118,103,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,50,48,48,48,47,115,118,103,34,10,32,32,32,120,109,108,110,115,61,34,
104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,50,48,48,48,47,115,118,103,34,10,32,32,32,120,109,108,110,115,58,115,111,100,105,112,111,100,105,61,34,104,116,116,112,58,47,47,115,111,
100,105,112,111,100,105,46,115,111,117,114,99,101,102,111,114,103,101,46,110,101,116,47,68,84,68,47,115,111,100,105,112,111,100,105,45,48,46,100,116,100,34,10,32,32,32,120,109,108,110,115,58,105,110,107,
115,99,97,112,101,61,34,104,116,116,112,58,47,47,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,47,110,97,109,101,115,112,97,99,101,115,47,105,110,107,115,99,97,112,101,34,10,32,32,32,118,
105,101,119,66,111,120,61,34,48,32,45,50,53,54,32,49,55,57,50,32,49,55,57,50,34,10,32,32,32,105,100,61,34,115,118,103,51,48,49,51,34,10,32,32,32,118,101,114,115,105,111,110,61,34,49,46,49,34,10,32,32,
32,105,110,107,115,99,97,112,101,58,118,101,114,115,105,111,110,61,34,48,46,52,56,46,51,46,49,32,114,57,56,56,54,34,10,32,32,32,119,105,100,116,104,61,34,49,48,48,37,34,10,32,32,32,104,101,105,103,104,
116,61,34,49,48,48,37,34,10,32,32,32,115,111,100,105,112,111,100,105,58,100,111,99,110,97,109,101,61,34,97,114,114,111,119,95,114,105,103,104,116,95,102,111,110,116,95,97,119,101,115,111,109,101,46,115,
118,103,34,62,10,32,32,60,109,101,116,97,100,97,116,97,10,32,32,32,32,32,105,100,61,34,109,101,116,97,100,97,116,97,51,48,50,51,34,62,10,32,32,32,32,60,114,100,102,58,82,68,70,62,10,32,32,32,32,32,32,
60,99,99,58,87,111,114,107,10,32,32,32,32,32,32,32,32,32,114,100,102,58,97,98,111,117,116,61,34,34,62,10,32,32,32,32,32,32,32,32,60,100,99,58,102,111,114,109,97,116,62,105,109,97,103,101,47,115,118,103,
43,120,109,108,60,47,100,99,58,102,111,114,109,97,116,62,10,32,32,32,32,32,32,32,32,60,100,99,58,116,121,112,101,10,32,32,32,32,32,32,32,32,32,32,32,114,100,102,58,114,101,115,111,117,114,99,101,61,34,
104,116,116,112,58,47,47,112,117,114,108,46,111,114,103,47,100,99,47,100,99,109,105,116,121,112,101,47,83,116,105,108,108,73,109,97,103,101,34,32,47,62,10,32,32,32,32,32,32,60,47,99,99,58,87,111,114,107,
62,10,32,32,32,32,60,47,114,100,102,58,82,68,70,62,10,32,32,60,47,109,101,116,97,100,97,116,97,62,10,32,32,60,100,101,102,115,10,32,32,32,32,32,105,100,61,34,100,101,102,115,51,48,50,49,34,32,47,62,10,
32,32,60,115,111,100,105,112,111,100,105,58,110,97,109,101,100,118,105,101,119,10,32,32,32,32,32,112,97,103,101,99,111,108,111,114,61,34,35,102,102,102,102,102,102,34,10,32,32,32,32,32,98,111,114,100,
101,114,99,111,108,111,114,61,34,35,54,54,54,54,54,54,34,10,32,32,32,32,32,98,111,114,100,101,114,111,112,97,99,105,116,121,61,34,49,34,10,32,32,32,32,32,111,98,106,101,99,116,116,111,108,101,114,97,110,
99,101,61,34,49,48,34,10,32,32,32,32,32,103,114,105,100,116,111,108,101,114,97,110,99,101,61,34,49,48,34,10,32,32,32,32,32,103,117,105,100,101,116,111,108,101,114,97,110,99,101,61,34,49,48,34,10,32,32,
32,32,32,105,110,107,115,99,97,112,101,58,112,97,103,101,111,112,97,99,105,116,121,61,34,48,34,10,32,32,32,32,32,105,110,107,115,99,97,112,101,58,112,97,103,101,115,104,97,100,111,119,61,34,50,34,10,32,
32,32,32,32,105,110,107,115,99,97,112,101,58,119,105,110,100,111,119,45,119,105,100,116,104,61,34,54,52,48,34,10,32,32,32,32,32,105,110,107,115,99,97,112,101,58,119,105,110,100,111,119,45,104,101,105,
103,104,116,61,34,52,56,48,34,10,32,32,32,32,32,105,100,61,34,110,97,109,101,100,118,105,101,119,51,48,49,57,34,10,32,32,32,32,32,115,104,111,119,103,114,105,100,61,34,102,97,108,115,101,34,10,32,32,32,
32,32,105,110,107,115,99,97,112,101,58,122,111,111,109,61,34,48,46,49,51,49,54,57,54,52,51,34,10,32,32,32,32,32,105,110,107,115,99,97,112,101,58,99,120,61,34,56,57,54,34,10,32,32,32,32,32,105,110,107,
115,99,97,112,101,58,99,121,61,34,56,57,54,34,10,32,32,32,32,32,105,110,107,115,99,97,112,101,58,119,105,110,100,111,119,45,120,61,34,48,34,10,32,32,32,32,32,105,110,107,115,99,97,112,101,58,119,105,110,
100,111,119,45,121,61,34,50,53,34,10,32,32,32,32,32,105,110,107,115,99,97,112,101,58,119,105,110,100,111,119,45,109,97,120,105,109,105,122,101,100,61,34,48,34,10,32,32,32,32,32,105,110,107,115,99,97,112,
101,58,99,117,114,114,101,110,116,45,108,97,121,101,114,61,34,115,118,103,51,48,49,51,34,32,47,62,10,32,32,60,103,10,32,32,32,32,32,116,114,97,110,115,102,111,114,109,61,34,109,97,116,114,105,120,40,49,
44,48,44,48,44,45,49,44,49,52,52,46,50,55,49,49,57,44,49,50,53,53,46,48,53,48,56,41,34,10,32,32,32,32,32,105,100,61,34,103,51,48,49,53,34,62,10,32,32,32,32,60,112,97,116,104,10,32,32,32,32,32,32,32,100,
61,34,109,32,49,52,55,50,44,53,55,54,32,113,32,48,44,45,53,52,32,45,51,55,44,45,57,49,32,76,32,55,56,52,44,45,49,54,54,32,113,32,45,51,57,44,45,51,55,32,45,57,49,44,45,51,55,32,45,53,49,44,48,32,45,57,
48,44,51,55,32,108,32,45,55,53,44,55,53,32,113,32,45,51,56,44,51,56,32,45,51,56,44,57,49,32,48,44,53,51,32,51,56,44,57,49,32,76,32,56,50,49,44,51,56,52,32,72,32,49,49,55,32,81,32,54,53,44,51,56,52,32,
51,50,46,53,44,52,50,49,46,53,32,48,44,52,53,57,32,48,44,53,49,50,32,86,32,54,52,48,32,81,32,48,44,54,57,51,32,51,50,46,53,44,55,51,48,46,53,32,54,53,44,55,54,56,32,49,49,55,44,55,54,56,32,104,32,55,48,
52,32,108,32,45,50,57,51,44,50,57,52,32,113,32,45,51,56,44,51,54,32,45,51,56,44,57,48,32,48,44,53,52,32,51,56,44,57,48,32,108,32,55,53,44,55,53,32,113,32,51,56,44,51,56,32,57,48,44,51,56,32,53,51,44,48,
32,57,49,44,45,51,56,32,108,32,54,53,49,44,45,54,53,49,32,113,32,51,55,44,45,51,53,32,51,55,44,45,57,48,32,122,34,10,32,32,32,32,32,32,32,105,100,61,34,112,97,116,104,51,48,49,55,34,10,32,32,32,32,32,
32,32,105,110,107,115,99,97,112,101,58,99,111,110,110,101,99,116,111,114,45,99,117,114,118,97,116,117,114,101,61,34,48,34,10,32,32,32,32,32,32,32,115,116,121,108,101,61,34,102,105,108,108,58,99,117,114,
114,101,110,116,67,111,108,111,114,34,32,47,62,10,32,32,60,47,103,62,10,60,47,115,118,103,62,10,0,0};

const char* imaphone_component::fa_arrow_right_svg = (const char*) resource_imaphone_component_fa_arrow_right_svg;
const int imaphone_component::fa_arrow_right_svgSize = 1966;


//[EndFile] You can add extra defines here...
//[/EndFile]
