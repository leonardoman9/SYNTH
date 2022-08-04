/*
  ==============================================================================

    Oscilloscope.h
    Created: 3 Aug 2022 7:03:15pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Oscilloscope  : public juce::Component
{
public:
    Oscilloscope();
    ~Oscilloscope() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscilloscope)
};
