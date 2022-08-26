/*
  ==============================================================================

    OscComponent.h
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
    
    OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId, juce::String fmFreqId, juce::String fmDepthId, juce::String gainId,juce::String pitchId);
    ~OscComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox oscWaveSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveSelectorAttachment;
    
    juce::Slider fmFreqSlider;
    juce::Slider fmDepthSlider;
    juce::Slider gainSlider;
    juce::Slider pitchSlider;
    
    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    std::unique_ptr<Attachment> fmFreqAttachment;
    std::unique_ptr<Attachment> fmDepthAttachment;
    std::unique_ptr<Attachment> gainAttachment;
    std::unique_ptr<Attachment> pitchAttachment;
    
    juce::Label waveSelectorLabel { "Wave Type", "Wave Type" };
    juce::Label fmFreqLabel { "FM Freq", "FM Freq" };
    juce::Label fmDepthLabel { "FM Depth", "FM Depth" };
    juce::Label gainLabel {"Gain", "Gain"};
    juce::Label pitchLabel{"Pitch", "Pitch"};
    
    
    void setSliderWithLabel (juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscComponent)
};
