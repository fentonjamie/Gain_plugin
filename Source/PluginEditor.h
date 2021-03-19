/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Gain_PluginAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener
{
public:
    Gain_PluginAudioProcessorEditor (Gain_PluginAudioProcessor&);
    ~Gain_PluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged (juce::Slider *slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Gain_PluginAudioProcessor& audioProcessor; //this connects GUI to the processor
    
    juce::Slider gainSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gain_PluginAudioProcessorEditor)
};
