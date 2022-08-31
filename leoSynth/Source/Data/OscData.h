/*
  ==============================================================================

    OscData.h
    Author:  Leonardo Mannini

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void setWaveType (const int choice);
    void setGain (const float levelInDecibels);
    void setPitch(int pitch);
    void setWaveFrequency (const int midiNoteNumber);
    void getNextAudioBlock (juce::dsp::AudioBlock<float>& block);
    void updateFm (const float freq, const float depth);
    float processNextSample(float input);
    
private:
    void processFmOsc (juce::dsp::AudioBlock<float>& block);
    juce::dsp::Oscillator<float> fmOsc { [](float x) { return std::sin (x); } };
    juce::dsp::Gain<float> gain;
    float fmMod { 0.0f };
    float fmDepth { 0.0f };
    int lastMidiNote { 0 };
};
