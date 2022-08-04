/*
  ==============================================================================

    Keyboard.cpp
    Created: 3 Aug 2022 7:10:44pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Keyboard.h"

//==============================================================================
Keyboard::Keyboard()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Keyboard::~Keyboard()
{
}

void Keyboard::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (5);
         auto labelSpace = bounds.removeFromTop (25.0f);
         g.fillAll (juce::Colours::black);
         g.setColour (juce::Colours::white);
         g.setFont (20.0f);
         g.drawText ("Keyboard", labelSpace.withX (5), juce::Justification::left);
         g.drawRoundedRectangle (bounds.toFloat(), 5.0f, 2.0f);
}

void Keyboard::resized()
{
    const auto startY = 55;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
}
