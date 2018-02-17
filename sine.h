#pragma once

#include "oscillator.h"

class Sine final : public Oscillator {

public:
	Sine();
	~Sine();
	void setFrequency(int frequency) override final;
	void processSamples(float (&buffer)[BUFFERSIZE]) override final;
};