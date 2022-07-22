/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"

//==============================================================================
/**
*/
class leoSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    leoSynthAudioProcessorEditor (leoSynthAudioProcessor&);
    ~leoSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox oscSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;
    leoSynthAudioProcessor& audioProcessor;
    AdsrComponent adsr;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (leoSynthAudioProcessorEditor)
};
