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


void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    process(juce::dsp::ProcessContextReplacing<float>(block));

}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency (juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}
