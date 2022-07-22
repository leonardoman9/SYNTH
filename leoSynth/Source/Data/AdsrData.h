/*
  ==============================================================================

    AdsrData.h
    Created: 22 Jul 2022 4:11:42pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);

    
private:    
    juce::ADSR::Parameters adsrParams;
};
