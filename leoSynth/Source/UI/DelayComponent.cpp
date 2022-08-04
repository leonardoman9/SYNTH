/*
  ==============================================================================

    DelayComponent.cpp
    Created: 3 Aug 2022 4:49:49pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DelayComponent.h"

//==============================================================================
DelayComponent::DelayComponent(juce::AudioProcessorValueTreeState& apvts, juce::String delayTimeId, juce::String delayFeedbackId)
{
    setSliderWithLabel(delayTimeSlider, delayTimeLabel, apvts, delayTimeId, delayTimeAttachment);
    setSliderWithLabel(delayFeedbackSlider, delayFeedbackLabel, apvts, delayFeedbackId, delayFeedbackAttachment);

}

DelayComponent::~DelayComponent()
{
}

void DelayComponent::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (5);
    auto labelSpace = bounds.removeFromTop (25.0f);
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (20.0f);
    g.drawText ("Delay", labelSpace.withX (5), juce::Justification::left);
    g.drawRoundedRectangle (bounds.toFloat(), 5.0f, 2.0f);
    
}

void DelayComponent::resized()
{
    const auto startY = 55;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;

    //TIME
    delayTimeSlider.setBounds (10, startY + 5, sliderWidth, sliderHeight);
    delayTimeLabel.setBounds (10, startY - labelYOffset, 90, labelHeight);
    
    //FEEDBACK
    delayFeedbackSlider.setBounds(delayTimeSlider.getRight(), startY, sliderWidth, sliderHeight);
    delayFeedbackLabel.setBounds(delayFeedbackSlider.getX(), delayFeedbackSlider.getY()-labelYOffset, delayFeedbackSlider.getWidth(), labelHeight);


}

using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;

void DelayComponent::setSliderWithLabel (juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible (slider);
    
    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);
    
    label.setColour (juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setFont (15.0f);
    label.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (label);
}
