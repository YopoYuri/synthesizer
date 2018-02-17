#include "sine.h"

Sine::Sine() {

	amplitude = 0.2;

	std::cout << "construction of Sine object" << std::endl;
}

Sine::~Sine() {

	std::cout << "destruction of Sine object" << std::endl;
}

void Sine::setFrequency(int frequency) {

	this->frequency = frequency;
}

void Sine::processSamples(float (&buffer)[BUFFERSIZE]) {

	static auto x = 0;
	static const auto samplesPerCycle  = SAMPLERATE / frequency;
	static const auto radiansPerSample = M_PI * 2 / samplesPerCycle;

	for (auto i = 0; i <= BUFFERSIZE; i += N_CHANNELS) {

   		buffer[i]   = amplitude * sin(x * radiansPerSample);
    		buffer[i+1] = amplitude * sin(x * radiansPerSample);
    		x++;

    		if (x >= samplesPerCycle) x = 0;
  	}
}
