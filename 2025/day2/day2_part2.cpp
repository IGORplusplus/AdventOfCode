#include <cmath>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

bool isRepeated(std::string s) {
    for(int i=1; i<=s.length() / 2; i++) {
	if (s.length() % i != 0)
	    continue;
	std::string block = s.substr(0, i);
	bool repeat = true;
	for(int j = i; j < s.length(); j += i) {
	    if(s.substr(j, i) != block) {
		repeat = false;
		break;
	    }
	}
	if(repeat)
	    return true;
    }
    return false;
}

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while(std::getline(ss, token, delimiter)) {
	tokens.push_back(token);
    }
    return tokens;
}

int main(int argc, char *argv[]) {

    std::ifstream inputFile;
    inputFile.open("puzzle_input.txt");

    std::vector<std::string> puzzleInput;
    std::string input;
    std::getline(inputFile, input);

    auto inputs = splitString(input, ',');
    std::vector<std::vector<std::string>> separatedInputs;
    std::vector<std::vector<uint64_t>> parsedInputs;
    separatedInputs.reserve(inputs.size());
    parsedInputs.reserve(inputs.size());
    for(int i=0; i<inputs.size(); i++) {
	separatedInputs.push_back(splitString(inputs[i], '-'));
	std::vector<uint64_t> row;
	row.push_back(std::stoull(separatedInputs[i][0]));
	row.push_back(std::stoull(separatedInputs[i][1]));
	parsedInputs.push_back(row);
    }

    std::vector<uint64_t> differences;
    for(int i=0; i<separatedInputs.size(); i++) {
	differences.push_back(parsedInputs[i][1] - parsedInputs[i][0]);
    }
    std::uint64_t totalInvalid = 0;

    for(uint64_t i=0; i<parsedInputs.size(); i++) {
	for(uint64_t j=0; j<=differences[i]; j++) {
	    uint64_t n = parsedInputs[i][0] + j;

	    std::string nString = std::to_string(n);
	    if(isRepeated(nString)) {
		totalInvalid += n;
	    }
	}
    }
    std::cout << totalInvalid << std::endl;

    return 0;
}
