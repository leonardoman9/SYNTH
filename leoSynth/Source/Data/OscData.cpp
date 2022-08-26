/*
  ==============================================================================

    OscData.cpp
    Author:  Leonardo Mannini

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels)
{
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    prepare (spec);
    fmOsc.prepare (spec);
}

void OscData::setWaveType (const int choice)
{
    switch (choice)
    {
        case 0:
            // Sine
            initialise ([](float x) { return std::sin (x); });
            break;
            
        case 1:
            // Saw wave
            initialise ([](float x) { return x / juce::MathConstants<float>::pi; });
            break;
            
        case 2:
            // Square wave
            initialise ([](float x) { return x < 0.0f ? -1.0f : 1.0f; });
            break;
            
        default:
            jassertfalse;   // You're not supposed to be here!
            break;
    }
}


float OscData::processNextSample (float input)
{
    fmMod = fmOsc.processSample (input) * fmDepth;
    return gain.processSample (processSample (input));
}

void OscData::setWaveFrequency (const int midiNoteNumber)
{
    setFrequency (juce::MidiMessage::getMidiNoteInHertz (midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
}

void OscData::getNextAudioBlock (juce::dsp::AudioBlock<float>& block)
{
    processFmOsc (block);
    process (juce::dsp::ProcessContextReplacing<float> (block));
}

void OscData::processFmOsc (juce::dsp::AudioBlock<float>& block)
{
    for (int ch = 0; ch < block.getNumChannels(); ++ch)
    {
        for (int s = 0; s < block.getNumSamples(); ++s)
        {
            fmMod = fmOsc.processSample (block.getSample (ch, s)) * fmDepth;
        }
    }
}
void OscData::setGain (const float levelInDecibels)
{
    gain.setGainDecibels (levelInDecibels);
}
void OscData::updateFm (const float freq, const float depth)
{
    fmOsc.setFrequency (freq);
    fmDepth = depth;
    auto currentFreq = juce::MidiMessage::getMidiNoteInHertz (lastMidiNote) + fmMod;
    setFrequency (currentFreq >= 0 ? currentFreq : currentFreq * -1.0f);
}
