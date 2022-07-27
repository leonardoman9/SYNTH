/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
leoSynthAudioProcessorEditor::leoSynthAudioProcessorEditor (leoSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc (audioProcessor.apvts, "OSC1WAVETYPE", "OSC1FMFREQ", "OSC1FMDEPTH"), adsr (audioProcessor.apvts)
{
    setSize (400, 300);
    addAndMakeVisible (osc);
    addAndMakeVisible (adsr);
}

leoSynthAudioProcessorEditor::~leoSynthAudioProcessorEditor()
{
}

//==============================================================================
void leoSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void leoSynthAudioProcessorEditor::resized()
{
    osc.setBounds (10, 10, 180, 200);
    adsr.setBounds (getWidth() / 2, 0, getWidth() / 2, getHeight());
}


