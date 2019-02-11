
/* program to build a DFA from input and feed argument symbols to it */

#include <iostream>
#include "src/dfa.h"

int main(int argc, char *argv[]) {
	// build DFA from file
	std::ifstream ifile(argv[1]);
	DFA dfa(ifile);

	// create input symbols to feed to DFA
	std::vector<std::string> input_symbols(argv+2, argv+argc);
	input_symbols.push_back(eof);

	// feed input symbols to the DFA
	if (!dfa.run(input_symbols)) {
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}
}
