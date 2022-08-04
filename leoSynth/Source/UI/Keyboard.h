/*
  ==============================================================================

    Keyboard.h
    Created: 3 Aug 2022 7:10:44pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Keyboard  : public juce::Component
{
public:
    Keyboard();
    ~Keyboard() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Keyboard)
};
