#pragma once

#include <memory>
#include <vector>
#include "sine.h"
#include "audio_io.h"

#define N_OSCILLATORS 1

class Synth {

public:
	Synth();
	~Synth();
	void init();
	void processAudio();

	Audio_IO stream;
	vector<unique_ptr<Oscillator>> oscillators;
	bool running;
};