#include <thread>
#include "synth.h"

int main() {

	static Synth synth;

	synth.init();
	std::thread audioThread(&Synth::processAudio, &synth);
	std::thread interfaceThread(&Synth::interface, &synth);
	audioThread.join();
	interfaceThread.join();
}




