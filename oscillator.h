#pragma once

#include <iostream> 
#include <math.h>

#define SAMPLERATE 44100
#define N_CHANNELS 2
#define FRAMES 512
#define BUFFERSIZE 2 * FRAMES

class Oscillator {

public:
	Oscillator();
	~Oscillator();
	virtual void setFrequency(int frequency){ };
	virtual void processSamples(float (&buffer)[BUFFERSIZE]){ };

	int frequency;
	float amplitude;
};
