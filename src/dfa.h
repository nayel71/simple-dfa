#ifndef DFA_H
#define DFA_H

#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>

extern std::string empty;
extern std::string eof;

class DFA {
	std::set<std::string> states;
	std::string start_state;
	std::set<std::string> final_states;

	// the transition function
	// transition_function(input_state, transition_symbol) -> output_state, output_symbol
	// input_state and output_state must be elements of states
	std::map<std::pair<std::string, std::string>, std::pair<std::string, std::string> > transition_function;

	std::string transition_state(std::string state, std::string symbol) { 
		return transition_function[std::make_pair(state, symbol)].first;
	}

	std::string transition_output(std::string state, std::string symbol) { 
		return transition_function[std::make_pair(state, symbol)].second;
	}

	// helper functions to read data from a .dfa file
	void read_set(std::set<std::string> &s, std::ifstream &file);
	void read_start(std::ifstream &file) { file >> start_state; }
	void read_transitions(std::ifstream &file);

public:
	// the constructor; reads data from a .dfa file
	DFA(std::ifstream &file);

	// runs the DFA
	bool run(std::vector<std::string> &input_symbols);
};

#endif /* DFA_H */
