#include "synth.h"

Synth::Synth() {

	running = true;

	for (auto i = 0; i < N_OSCILLATORS; i++) {

		oscillators.emplace_back(new Sine);
		oscillators[i]->setFrequency(500);
	}

	stream.set_mode(AUDIO_IO_WRITEONLY);
	stream.set_samplerate(SAMPLERATE);
	stream.set_nrofchannels(N_CHANNELS);
	stream.set_framesperbuffer(FRAMES);
}

Synth::~Synth() {

	std::cout << "memory for oscillators freed" << std::endl;
}

void Synth::init() {

	stream.initialise();
	stream.list_devices();
	stream.set_output_device(2);
	stream.start_server();
}

void Synth::processAudio() {

	static float buffer[BUFFERSIZE];

	while (running) {
		for (auto &oscillator : oscillators) {

			oscillator->processSamples(buffer);
		}
		stream.write(buffer);
  	} 

  	stream.finalise();
}

void Synth::interface() {

	static char in;

	std::cout << "press 'q' to quit" << std::endl;
	std::cin >> in;

	if (in == 'q') running = false;
}



