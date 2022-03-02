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
class SimpleGUIControlAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                              private juce::Slider::Listener
{
public:
    SimpleGUIControlAudioProcessorEditor (SimpleGUIControlAudioProcessor&);
    ~SimpleGUIControlAudioProcessorEditor();

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (juce::Slider* slider) override
    {
        audioProcessor.noteOnVel = midiVolume.getValue();
    };
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleGUIControlAudioProcessor& audioProcessor;
    
    juce::Slider midiVolume;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleGUIControlAudioProcessorEditor)
};
