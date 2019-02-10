/* multigen i for an odd i > 0 will generate the DFA ../dfa/multi.dfa */

#include <iostream>
#include <fstream>
#include <bitset>

static void print_transition(int i, int n, std::ofstream &file) {
	file << i << ' ' << '0'     << ' ' << i/2               << ' ' << i%2     << std::endl;
	file << i << ' ' << '1'     << ' ' << (i+1)/2 + (n-1)/2 << ' ' << (i+1)%2 << std::endl;
	file << i << ' ' << "empty" << ' ' << i                 << ' ';
	if (i == 0) {
		file << "empty" << std::endl;
		return;
	} 
	std::string binary = std::bitset<32>(i).to_string();
	binary.erase(0, binary.find_first_not_of('0'));
	std::reverse(binary.begin(), binary.end());
	file << binary << std::endl;
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	std::ofstream file;
	std::string filename(argv[1]);
	filename = "../dfa/mult" + filename + ".dfa";
	file.open(filename);

	// states
	file << n << std::endl;
	for (int i = 0; i < n; i++) {
		file << i << std::endl;
	}

	// start state
	file << '0' << std::endl;

	// final states
	file << n << std::endl;
	for (int i = 0; i < n; i++) {
		file << i << std::endl;
	}

	// transitions
	file << 3*n << std::endl;
	for (int i = 0; i < n; i++) {
		print_transition(i, n, file);
	}
}
