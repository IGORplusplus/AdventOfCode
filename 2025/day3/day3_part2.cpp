#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define ASCII_OFFSET 48

using namespace std;

int main(int argc, char *argv[]) {
    ifstream inputStream;
    inputStream.open("puzzle_input.txt");
    // inputStream.open("puzzle_test.txt");

    string inputBuffer;
    vector<string> input;
    while(getline(inputStream, inputBuffer)) {
	input.push_back(inputBuffer);
    }

    /* for(int i=0; i<input.size(); i++) {
	cout << input[i] << endl;
    } */
    
    int max = 0;
    int next_starting_idx = 0;
    uint64_t battery_total = 0;

    for(int i=0; i<input.size(); i++) {
	string string_sequence = "";
	max = 0;
	next_starting_idx = 0;

	for(int digit_place = 11; digit_place >= 0; digit_place--) {
	    for(int j=next_starting_idx; j<input[i].size() - digit_place; j++) {
		if(input[i][j] > max) {
		    max = input[i][j];
		    next_starting_idx = j + 1;
		}
	    }
	    string_sequence.push_back(max);
	    max = 0;
	}
	uint64_t int_sequence = stoull(string_sequence);
	cout << i << ": " << int_sequence << endl;
	battery_total += int_sequence;

	string_sequence.clear();
    }
    cout << battery_total << endl;

    return 0;
}
