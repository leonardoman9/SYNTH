/*
  ==============================================================================

    FilterData.h
    Author:  Leonardo Mannini

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class FilterData : public juce::dsp::StateVariableTPTFilter<float>
{
public:
    void prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels);
    void process(juce::AudioBuffer<float>& buffer);
    void updateParameters(const int filterType, const float frequency, const float resonance, const float modulator = 1.0f);
    float processNextSample (int channel, float inputValue);
    void reset();
    
private:
    juce::dsp::StateVariableTPTFilter<float> filter;
    bool isPrepared {false};
};
