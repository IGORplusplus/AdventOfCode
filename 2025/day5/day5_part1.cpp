#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

vector<uint64_t> splitString(const string& source, char delimiter) {
    vector<uint64_t> range;
    string token;
    stringstream ss(source);
    uint64_t limit = 0;

    while(getline(ss, token, delimiter)) {
	limit = stoull(token);
	range.push_back(limit);
    }
    return range;
}

int main(int argc, char *argv[]) {
    fstream inputFile;
    // inputFile.open("puzzle_test.txt");
    inputFile.open("puzzle_input.txt");

    string inputBuffer;
    vector<string> input;

    while(getline(inputFile, inputBuffer)) {
	input.push_back(inputBuffer);
    }
    inputFile.close();

    vector<vector<uint64_t>> ranges;
    vector<uint64_t> values;

    int it=0;
    for(const string& line : input) {
	if(line == "")
	    break;
	ranges.push_back(splitString(line, '-'));
	it++;
    }

    //skip whitespace
    it++;

    for(int i=it; i<input.size();i++) {
	values.push_back(stoull(input[i]));
    }

    int total = 0;
    for(int i=0; i<values.size(); i++) {
	for(int j=0; j<ranges.size(); j++) {
	    uint64_t range = ranges[j][1] - ranges[j][0];
	    uint64_t difference = ranges[j][1] - values[i];
	    if(difference < range) {
		total++;
		break;
	    }
	    if(ranges[j][0] == values[i] || ranges[j][1] == values[i]) {
		total++;
		break;
	    }
	}
    }

    cout << total << endl;

    return 0;
}
