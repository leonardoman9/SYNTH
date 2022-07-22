/*
  ==============================================================================

    AdsrData.cpp
    Created: 22 Jul 2022 4:11:42pm
    Author:  Leonardo Mannini

  ==============================================================================
*/

#include "AdsrData.h"
void AdsrData::updateADSR(const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.decay = release;

    setParameters(adsrParams);

}
