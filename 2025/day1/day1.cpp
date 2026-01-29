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

	    if(abs(rotation) > dial) {
		int difference = dial - rotation;
		difference %= 100;
		dial = 100 + difference;
	    } else {
		dial -= rotation;
	    }

	    dial %= 100;
	    funString.clear();
	    if(dial ==  0) {
		total++;
	    }

	} else if (stringData[i][0] == 'R') {
	    for(int j=1; stringData[i][j] != '\0'; j++) {
		funString.push_back(stringData[i][j]);
	    }
	    // std::cout << funString << std::endl;
	    int rotation = 0;
	    try {
		rotation = std::stoi(funString);

	    } catch (const std::invalid_argument& e){
		std::cerr << "Invalid argument" << e.what() << std::endl;
	    } catch (const std::out_of_range& e) {
		std::cerr << "out of range" << e.what() << std::endl;
	    }

	    dial += rotation;
	    dial %= 100;

	    funString.clear();
	    if(dial ==  0) {
		total++;
	    }
	}
    }

    std::cout << "TOTAL: " << total << std::endl;

    return 0;
} 
