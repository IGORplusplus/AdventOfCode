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
    
    //there will be two pointers I guess
    char max_first = '0';
    int idx_first = -1;

    char max_second = '0';
    int idx_second = -1;
    int battery_total = 0;

    for(int i=0; i<input.size(); i++) {
	for(int j=0; j<input[i].size() - 1; j++) {
	    if(input[i][j] > max_first) {
		max_first = input[i][j];
		idx_first = j;
	    }
	}
	for(int k=idx_first + 1; k<input[i].size(); k++) {
	    if(input[i][k] > max_second) {
		max_second = input[i][k];
		idx_second = k;
	    }
	}
	int ascii_first = static_cast<int>(max_first);
	int ascii_second = static_cast<int>(max_second);

	if(idx_first < idx_second ) {
	    battery_total += ((ascii_first - ASCII_OFFSET) * 10) + (ascii_second - ASCII_OFFSET);
	    cout << ascii_first - ASCII_OFFSET << "   " << ascii_second - ASCII_OFFSET << endl;
	} /* else {
	    battery_total += ((ascii_second - ASCII_OFFSET) * 10) + (ascii_first - ASCII_OFFSET);
	    cout << ascii_second - ASCII_OFFSET << "   " << ascii_first - ASCII_OFFSET << endl;
	} */

	max_first = '0';
	max_second = '0';
	idx_first = -1;
	idx_second = -1;
    }
    cout << battery_total << endl;

    return 0;
}
