//part B of day 2 2025
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


bool unsafeFunction(vector<int> numbers){
	int num;
	int numBefore = 0;
	bool decreasing = false;
	bool increasing = false;
	bool unsafe = false;
	for(int i=1; i < numbers.size();i++) {
		if(numbers.at(i) > numbers.at(numBefore) && !decreasing){
				if( numbers.at(i) - numbers.at(numBefore) > 3){
					unsafe = true;
					break;
				}
				increasing = true;
			}
			else if(numbers.at(i) < numbers.at(numBefore) && !increasing){
				if(numbers.at(numBefore) - numbers.at(i) > 3){
					unsafe = true;
					break;
				}
				decreasing = true;
			}
			else{ unsafe = true; break; }
			numBefore++;
	}
	if(unsafe) {
		return false;
	}
	else{
		return true;
	}
}

int main() {
	ifstream inputFile;
	inputFile.open("puzzleInput.txt");
	int num;	
	vector<int> input;
	string line;
	int numSafe = 0;
	int unsafe = 0;

	while(getline(inputFile, line)){
		stringstream ss(line);
		vector<int> numbers;
		


		while(ss >> num) {
			numbers.push_back(num);
		}
		
		if(!unsafeFunction(numbers)){
			unsafe++;
			for(int i=0; i<numbers.size();i++) {
				vector<int> numCopy = numbers;
				numCopy.erase(numCopy.begin() + i);
				if(!unsafeFunction(numCopy)){
					unsafe++;
				}
			}	
				cout << unsafe << endl;
		}

		if(unsafe <= numbers.size()){numSafe++;}
		unsafe = 0;
		//cout << line << endl;
	}
	cout << "The number of safe entries: " << numSafe << endl;

	return 0;
}
