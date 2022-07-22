/*
  ==============================================================================

    OscData.h
    Created: 22 Jul 2022 5:31:14pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay ( juce::dsp::ProcessSpec& spec);
    void setWaveType(const int choice);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);
    void setWaveFrequency (const int midiNoteNumber);
    void setFmParams(const float depth, const float frequency);

private:
    juce::dsp::Oscillator<float> fmOsc{ [] (float x) {return std::sin(x);}};
    float fmMod{0.0f};
    float fmDepth{0.0f};
    int lastMidiNote{0};
};
//juce::dsp::Oscillator<float> osc{ [](float x) {return x / juce::MathConstants<float>::pi;  } };
