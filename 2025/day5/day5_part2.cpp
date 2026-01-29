#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

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

    int it=0;
    for(const string& line : input) {
	if(line == "")
	    break;
	ranges.push_back(splitString(line, '-'));
	it++;
    }

    //they are all sorted with this lambda
    sort(ranges.begin(), ranges.end(),
	 [](auto& a, auto& b) {
	 return a[0] < b[0];
	 });

    uint64_t total_fresh = 0;
    uint64_t curr_start = 0;
    uint64_t curr_end = 0;
    for(size_t i=0; i < ranges.size(); i++) {
	curr_start = ranges[i][0];
	if(ranges[i][0] > curr_end) {
	    curr_start = ranges[i][0];
	    curr_end = ranges[i][1];
	    total_fresh += ranges[i][1] - ranges[i][0] + 1;
	    cout << ranges[i][1] - ranges[i][0] + 1 << endl;;
	} else if(ranges[i][0] <= curr_end && ranges[i][1] > curr_end) {
	    total_fresh += ranges[i][1] - curr_end;
	    cout << ranges[i][1] - curr_end << endl;
	    curr_start = ranges[i][0];
	    curr_end = ranges[i][1];
	} else {
	    continue;
	}
	cout << "current start:  " << curr_start;
	cout << "   current end:  " << curr_end << endl;
    }

    cout << total_fresh << endl;

    return 0;
}
