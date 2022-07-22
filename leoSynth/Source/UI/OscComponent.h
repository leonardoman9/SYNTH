/*
  ==============================================================================

    OscComponent.h
    Created: 22 Jul 2022 5:54:09pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class OscComponent  : public juce::Component
{
public:
    OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId);
    ~OscComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox oscWaveSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveSelectorAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscComponent)
};
