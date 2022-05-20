/*
  ==============================================================================

    SynthSound.h
    Created: 20 May 2022 5:46:54pm
    Author:  leona

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
    public:
        bool appliesToNote(int midiNoteNumber) override { return true; }
        bool appliesToChannel(int midiChannel) override { return true; }


};