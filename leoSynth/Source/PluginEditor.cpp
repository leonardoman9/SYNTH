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
osc (audioProcessor.apvts, "OSCWAVETYPE", "OSCFMFREQ", "OSCFMDEPTH"),
adsr("Amp Envelope", audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE"),
filter(audioProcessor.apvts, "FILTERTYPE", "FILTERFREQ", "FILTERRES"),
modAdsr("Mod Envelope", audioProcessor.apvts, "MODATTACK", "MODDECAY", "MODSUSTAIN", "MODRELEASE"),

delay(audioProcessor.apvts, "DELAYTIME", "DELAYFEEDBACK"),
oscilloscope(),
keyboard()

{
   
    setSize (1280, 800);
    addAndMakeVisible (osc);
    addAndMakeVisible (adsr);
    addAndMakeVisible(filter);
    addAndMakeVisible(modAdsr);
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
    const auto paddingX = 5;
    const auto paddingY = 35;
    const auto paddingY2 = 235;
    const auto paddingY3 = 435;
    const auto paddingY4 = 635;
    const auto width = 300;
    const auto height = 200;


    osc.setBounds (paddingX, paddingY, width, height);
    adsr.setBounds (osc.getRight(), paddingY, width, height);
    filter.setBounds(paddingX, paddingY2, width, height);
    modAdsr.setBounds(filter.getRight(), paddingY2, width, height);
    
}


