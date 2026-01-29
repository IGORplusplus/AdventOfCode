#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ifstream inputFile;
	inputFile.open("puzzleInput.txt");
	
	vector<int> input;

	string line;
	int numSafe = 0;

	while(getline(inputFile, line)){
		stringstream ss(line);
		vector<int> numbers;
		int num;
		int numBefore = 0;
		bool decreasing = false;
		bool increasing = false;
		bool unsafe = false;

		while(ss >> num) {
			numbers.push_back(num);
		}
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

		if(!unsafe) {
			numSafe++;
		}
		cout << line << endl;
	
	}
	cout << "The number of safe entries: " << numSafe << endl;

	return 0;
}
