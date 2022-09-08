/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
leoSynthAudioProcessorEditor::leoSynthAudioProcessorEditor (leoSynthAudioProcessor& p)
    : AudioProcessorEditor (&p),
audioProcessor (p),
osc (audioProcessor.apvts, "OSCWAVETYPE", "OSCFMFREQ", "OSCFMDEPTH", "OSCGAIN", "OSC1PITCH", "Oscillatore 1"),
osc2 (audioProcessor.apvts, "OSCWAVETYPE2", "OSCFMFREQ2", "OSCFMDEPTH2", "OSCGAIN2", "OSC2PITCH", "Oscillatore 2"),
adsr("Amp Envelope", audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE"),
filter(audioProcessor.apvts, "FILTERTYPE", "FILTERFREQ", "FILTERRES"),
modAdsr("Mod Envelope", audioProcessor.apvts, "MODATTACK", "MODDECAY", "MODSUSTAIN", "MODRELEASE"),
delay(audioProcessor.apvts, "DELAYTIME", "DELAYFEEDBACK"),
oscilloscope(),
keyboard()

{
   
    setSize (620, 650);
    addAndMakeVisible (osc);
    addAndMakeVisible (adsr);
    addAndMakeVisible(filter);
    addAndMakeVisible(modAdsr);
    addAndMakeVisible(osc2);
}

leoSynthAudioProcessorEditor::~leoSynthAudioProcessorEditor()
{
}

//==============================================================================
void leoSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::red);
}

void leoSynthAudioProcessorEditor::resized()
{
    const auto paddingX = 5;
    const auto paddingY = 35;
    const auto paddingY2 = 235;

    const auto width = 300;
    const auto height = 200;
    const auto oscHeight = 300;


    osc.setBounds (paddingX, paddingY, width, oscHeight);
    osc2.setBounds(paddingX, osc.getBottom(), width, oscHeight);
    adsr.setBounds (osc.getRight(), paddingY, width, height);
    filter.setBounds(osc.getRight(), adsr.getBottom(), width, height);
    modAdsr.setBounds(osc2.getRight(), filter.getBottom(), width, height);
    
}


