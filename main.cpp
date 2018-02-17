#include "synth.h"

int main() {

	Synth synth;
	char in;

	synth.init();
	synth.processAudio();

	std::cout << "press 'q' to quit" << std::endl;
	std::cin >> in;
}



