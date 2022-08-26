/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"
#include "UI/OscComponent.h"
#include "UI/FilterComponent.h"
#include "UI/DelayComponent.h"
#include "UI/Oscilloscope.h"
#include "UI/Keyboard.h"

//==============================================================================
/**
*/
class leoSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    leoSynthAudioProcessorEditor (leoSynthAudioProcessor&);
    ~leoSynthAudioProcessorEditor() override;
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    leoSynthAudioProcessor& audioProcessor;
    OscComponent osc;
    OscComponent osc2;
    AdsrComponent adsr;
    FilterComponent filter;
    AdsrComponent modAdsr;

    
    DelayComponent delay;
    Oscilloscope oscilloscope;
    Keyboard keyboard;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (leoSynthAudioProcessorEditor)
};
