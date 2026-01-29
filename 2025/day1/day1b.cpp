#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

int main(int argc, char *argv[]) {

    std::ifstream inputFile;
    inputFile.open("puzzleinput.txt");

    std::string line;
    std::vector<std::string> stringData;

    while(getline(inputFile, line)) {
	stringData.push_back(line);
    }
    inputFile.close();

    int dial = 50;
    int total = 0;

    std::string funString = "";

    for(int i=0; i<stringData.size(); i++) {
	if (stringData[i][0] == 'L') {
	    for(int j=1; stringData[i][j] != '\0'; j++) {
		funString.push_back(stringData[i][j]);
	    }
	    // std::cout << (-1 * std::stoi(funString)) << std::endl;
	    int rotation = std::stoi(funString);
	    for(int k=0;k<rotation;k++) {
		dial--;
		if(dial == 0) {
		    total++;
		} else if(dial == -1) {
		    dial = 99;
		}
	    }
	    funString.clear();

	} else if (stringData[i][0] == 'R') {
	    for(int j=1; stringData[i][j] != '\0'; j++) {
		funString.push_back(stringData[i][j]);
	    }
	    // std::cout << funString << std::endl;
	    int rotation = std::stoi(funString);
	    for(int k=0;k<rotation;k++) {
		dial++;
		dial %= 100;
		if(dial == 0) {
		    total++;
		}
	    }
	    funString.clear();

	}
    }

    std::cout << "TOTAL: " << total << std::endl;

    return 0;
} 
