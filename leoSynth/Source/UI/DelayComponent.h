/*
  ==============================================================================

    DelayComponent.h
    Created: 3 Aug 2022 4:49:49pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class DelayComponent  : public juce::Component
{
public:
    DelayComponent(juce::AudioProcessorValueTreeState& apvts, juce::String delayTimeId, juce::String delayFeedbackId);
    ~DelayComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    juce::Slider delayTimeSlider;
    juce::Slider delayFeedbackSlider;
    std::unique_ptr<Attachment> delayTimeAttachment;
    std::unique_ptr<Attachment> delayFeedbackAttachment;
    juce::Label delayTimeLabel { "Delay Time", "Delay Time"};
    juce::Label delayFeedbackLabel { "Delay Feedback", "Delay Feedback" };
    void setSliderWithLabel (juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayComponent)
};
