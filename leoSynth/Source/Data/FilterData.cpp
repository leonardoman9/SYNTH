/*
  ==============================================================================

    FilterData.cpp
    Author:  Leonardo Mannini

  ==============================================================================
*/
#include "FilterData.h"

FilterData::FilterData()
{
    setType (juce::dsp::StateVariableTPTFilterType::lowpass);
}

void FilterData::setParams (const int filterType, const float filterCutoff, const float filterResonance, const float modulator)
{
    selectFilterType (filterType);
    float modFreq = filterCutoff * modulator;
    modFreq = std::fmin(std::fmax(modFreq, 20.0f), 20000.0f);
       
    setCutoffFrequency (modFreq);
    setResonance (filterResonance);
}

void FilterData::prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels)
{
    resetAll();
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    prepare (spec);
}


void FilterData::selectFilterType (const int filterType)
{
    switch (filterType)
    {
        case 0:
            setType (juce::dsp::StateVariableTPTFilterType::lowpass);
            break;
            
        case 1:
            setType (juce::dsp::StateVariableTPTFilterType::bandpass);
            break;
            
        case 2:
            setType (juce::dsp::StateVariableTPTFilterType::highpass);
            break;
            
        default:
            setType (juce::dsp::StateVariableTPTFilterType::lowpass);
            break;
    }
}

void FilterData::processNextBlock(juce::AudioBuffer<float>& buffer)
{
    juce::dsp::AudioBlock<float> block { buffer };
    process (juce::dsp::ProcessContextReplacing<float>(block));
}

float FilterData::processNextSample (int channel, float inputValue)
{
    return processSample (channel, inputValue);
}

void FilterData::resetAll()
{
    reset();
    lfo.reset();
}
