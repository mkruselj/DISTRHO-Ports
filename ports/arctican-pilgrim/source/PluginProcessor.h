/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef __PLUGINPROCESSOR_H_34DAFF0F__
#define __PLUGINPROCESSOR_H_34DAFF0F__

#include "JuceHeader.h"
#include "JucePluginCharacteristics.h"

#include "PluginParameter.h"


//==============================================================================
/**
*/
class ThePilgrimAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    ThePilgrimAudioProcessor();
    ~ThePilgrimAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    double getTailLengthSeconds() const { return 0.0; }

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

    String getStateInformationString ();
    void setStateInformationString (const String& data);

    bool silenceInProducesSilenceOut() const { return true; }

    //==============================================================================
    //	USER FUNCTIONS =============================================================
    //==============================================================================

	void updateFilter();

	PluginParameter filterParameter;
	PluginParameter mixParameter;

	IIRFilterOld highFilterL;
	IIRFilterOld highFilterR;
	IIRFilterOld lowFilterL;
	IIRFilterOld lowFilterR;

	double globalSampleRate;

	enum Parameters
    {
        filterFreqParam = 0,
		mixParam,

        totalNumParams
    };

	int contnumber;
	int contvalue;
	bool learnIsActive;
	int currentLearnParam;
	int lastMovedParam;


private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ThePilgrimAudioProcessor);

};

#endif  // __PLUGINPROCESSOR_H_34DAFF0F__