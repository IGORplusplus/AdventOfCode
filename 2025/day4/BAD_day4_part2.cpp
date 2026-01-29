#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int iterator_array[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool outOfBounds(int height, int width, int index[2]) {
    if(index[0] < 0 || index[1] < 0) {
	return true;
    } if(index[0] > height - 1 || index[1] > width - 1) {
	return true;
    }
    return false;
}

int adjacentCount(const vector<string>& input, int index[2]) {
    int iterator[2];
    int rollCount = 0;
    
    for(int i=0; i<8;i++) {
	iterator[0] = index[0] + iterator_array[i][0]; 
	iterator[1] = index[1] + iterator_array[i][1]; 

	if(outOfBounds(input.size(), input[0].size(), iterator) == true) {
	    continue;
	} else {
	    int x = iterator[0];
	    int y = iterator[1];
	    if(input[x][y] == '@')
		rollCount++;
	}
    }
    return rollCount;
}
	
int main(int argc, char *argv[]) {
    fstream inputFile;
    inputFile.open("puzzle_test.txt");
    // inputFile.open("puzzle_input.txt");

    string inputBuffer;
    vector<string> input;

    while(getline(inputFile, inputBuffer)) {
	input.push_back(inputBuffer);
    }
    inputFile.close();

    vector<vector<int>> freeCoords;
    bool change = true;

    while(change) {
	change = false;
	for(int i=0; i<input.size(); i++) {
	    for(int j=0; j<input[i].size(); j++) {

		int idx_pair[2] = {i, j};
		if(input[i][j] == '@' && adjacentCount(input, idx_pair) < 4) {
		    change = true;
		    freeCoords.push_back({j, i});
		}
	    }
	}
	if (!change) {
	    int totalLeft = 0;
	    for(int i=0; i<input.size(); i++) {
		for(int j=0; j<input[i].size(); j++) {
		    if(input[i][j] == '@')
			totalLeft++;
		}
	    }
	    cout << totalLeft << endl;
	    return 0;
	}

	for (const auto& freeCoord : freeCoords) {
	    input[freeCoord[1]][freeCoord[0]] = '.';
	}
	freeCoords.clear();
    }
}
