/*
  ==============================================================================

    Oscilloscope.cpp
    Created: 3 Aug 2022 7:03:15pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscilloscope.h"

//==============================================================================
Oscilloscope::Oscilloscope()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Oscilloscope::~Oscilloscope()
{
}

void Oscilloscope::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (5);
         auto labelSpace = bounds.removeFromTop (25.0f);
         g.fillAll (juce::Colours::black);
         g.setColour (juce::Colours::white);
         g.setFont (20.0f);
         g.drawText ("Oscilloscope", labelSpace.withX (5), juce::Justification::left);
         g.drawRoundedRectangle (bounds.toFloat(), 5.0f, 2.0f);
}

void Oscilloscope::resized()
{
    /*
    const auto startY = 55;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
     */
   
}


