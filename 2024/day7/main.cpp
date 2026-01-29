//day 7

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

bool findCombination(long firstNumber, const vector<long>& numbers, long number, int index){
    if (index >= numbers.size()) {
        return number == firstNumber;
    }

    long addNumber = number;
    long multiplyNumber = number;
    addNumber += numbers[index];
    multiplyNumber *= numbers[index];

    if(findCombination(firstNumber, numbers, addNumber, index + 1)) return true;
    if(findCombination(firstNumber, numbers, multiplyNumber, index + 1)) return true;

    return false;
}

long findAnswer(vector<long>firstNumbers, vector<vector<long>> numbers){
    long answer = 0;
    for(int i=0; i<firstNumbers.size(); i++){
	cout << i << endl;
	if(findCombination(firstNumbers[i], numbers[i], 0, 0)){
	    answer += firstNumbers[i];
	}
    }
    return answer;
}

int main(){

    cout << "Day 7" << endl << endl;

    ifstream f;
    f.open("puzzleinput.txt");

    string line;
    vector<string> lines;

    while(getline(f, line)){
	lines.push_back(line);
    }
    vector<long> firstNumbers;
    vector<string> firstStrings(lines.size());
    for(int i=0;i<lines.size();i++){
	for(int j=0;j<lines[i].size();j++){
	    if(lines[i][j] != ':'){
		firstStrings[i].push_back(lines[i][j]);
	    }
	    else{
		firstNumbers.push_back(stol(firstStrings[i]));
		//cout << fixed << setprecision(2) << firstNumbers[i] << endl;
		break;
	    }
	}
    }

    //time for a 2d vector
    vector<vector<long>> numbers;
    for(int i=0;i<lines.size();i++){
	vector<long> lineNumbers;
	size_t pos = lines[i].find(':');
	//should be the beginning of the first number
	string numberPart = lines[i].substr(pos + 2);
	stringstream ss(numberPart);
	int num;
	while(ss >> num){
	    lineNumbers.push_back(num);
	}
	numbers.push_back(lineNumbers);
	lineNumbers.clear();
    }

    long answer = findAnswer(firstNumbers, numbers);
    cout << "The correct Answer is " << answer << endl;

    return 0;
}
