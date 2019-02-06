#include <iostream>
#include "dfa.h"

std::string empty = "empty";
std::string eof = "";

DFA::DFA(std::ifstream &file) { 
	read_set(states, file);
	read_start(file);
	read_set(final_states, file);
	read_transitions(file);
}

void DFA::read_set(std::set<std::string> &s, std::ifstream &file) {
	int size;
	file >> size;
	for (int i = 0; i < size; i++) {
		std::string element;
		file >> element;
		s.insert(element);
	}
}	

void DFA::read_transitions(std::ifstream &file) {
	int num_transitions;
	file >> num_transitions;
	for (int i = 0; i < num_transitions; i++) {
		std::string istate, transition, ostate, output;
		file >> istate >> transition >> ostate >> output;
		if (transition == empty) {
			transition = eof;
		}
		if (output == empty) {
			output = eof;
		}
		transition_function.insert(std::make_pair(std::make_pair(istate, transition), std::make_pair(ostate, output)));
	}
}

bool DFA::run(std::vector<std::string> &input_symbols) {
	std::string current_state = start_state;
	for (auto &letter : input_symbols) {
		std::string output = transition_output(current_state, letter);
		std::cout << output;
		current_state = transition_state(current_state, letter);
	}
	std::cout << std::endl;
	return final_states.count(current_state);
}
