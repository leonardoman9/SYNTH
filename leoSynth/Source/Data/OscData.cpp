/*
  ==============================================================================

    OscData.cpp
    Created: 22 Jul 2022 5:31:14pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    fmOsc.prepare(spec);
    prepare (spec);
}
void OscData::setWaveType(const int choice)
{
    switch(choice){
        case 0:
            //SINE WAVE
            initialise([](float x) {return std::sin(x); } );
            break;
        case 1:
            //SAW WAVE
            initialise([](float x) { return x / juce::MathConstants<float>::pi; } );

            break;
        case 2:
            //SQUARE WAVE
            initialise([](float x) { return x < 0.0f ? -1.0f : 1.0f; } );
            break;
            
        default:
            jassertfalse; //Qualcosa è andato storto
            break;
    }
}


void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency (juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    for (int ch = 0; ch<block.getNumChannels(); ++ch)
    {
        for (int s = 0; s< block.getNumSamples(); ++s)
        {
            fmMod = fmOsc.processSample(block.getSample(ch, s)) * fmDepth; //value of a wave at a given point in time, multiplied * fm Depth
        }
    }
    process(juce::dsp::ProcessContextReplacing<float>(block));

}

void OscData::setFmParams(const float depth, const float freq)
{
    fmOsc.setFrequency(freq);
    fmDepth = depth;
    auto currentFreq =juce::MidiMessage::getMidiNoteInHertz(lastMidiNote)+ fmMod;
    //setFrequency (abs(currentFreq)); potrebbe funzionare?
    setFrequency(currentFreq >= 0 ? currentFreq : currentFreq * -1.0f);
}
