/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Gain_PluginAudioProcessorEditor::Gain_PluginAudioProcessorEditor (Gain_PluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    // set the parameters for the slider
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setTextValueSuffix("Db");
    gainSlider.setRange(-60.0, 0.0);
    gainSlider.setValue(-1.0);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

Gain_PluginAudioProcessorEditor::~Gain_PluginAudioProcessorEditor()
{
}

//==============================================================================
void Gain_PluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll(juce::Colours::lightblue);
    
    // set the main heading
    
    g.setColour(juce::Colours::black);
    g.setFont(20.0f);
    g.drawText("Gain Controller", getLocalBounds(), juce::Justification::centred, true);

}
// add the slider to UI
void Gain_PluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void Gain_PluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider){
    
    // what do we want to change when the slider is being changed
    
    if (slider == &gainSlider) // if the slider changing is our gain slider
    {
        audioProcessor.rawVolume = pow(10, gainSlider.getValue() / 20); // this converts the gain to a logarithmic DB scale
    }
}
