/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
leoSynthAudioProcessorEditor::leoSynthAudioProcessorEditor (leoSynthAudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p), adsr(audioProcessor.apvts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>
        (audioProcessor.apvts, "OSC",oscSelector);
    
    addAndMakeVisible(adsr);
}
 
leoSynthAudioProcessorEditor::~leoSynthAudioProcessorEditor()
{
}

//==============================================================================
void leoSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
   
}

void leoSynthAudioProcessorEditor::resized()
{
    adsr.setBounds(getWidth()/2, 0, getWidth()/2, getHeight());
}


