#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
using namespace std;


int main(){
	ifstream inputfile;
	inputfile.open("inputFile.txt");
	cout << "Reading from input.txt" << endl;
	int firstString;
	int counter = 0;
	string line;
	while(getline(inputfile, line)) {
		counter++;
	}
	
	cout << "Number of lines in file " << counter << endl;

	string inLine[counter];
	int lineCount = 0;
	//pull line pointer to beginning
	inputfile.clear(); // to clear eof flags
	inputfile.seekg(0, ios::beg);

	while(getline(inputfile, line) && lineCount < counter) {
		inLine[lineCount] = line;
	//	cout << inLine[lineCount] << endl;
		lineCount++;
	}
	
	string leftCol[counter];
	string rightCol[counter];

	int leftNum[counter];
	int rightNum[counter];
	
	for(int i=0; i<counter;i++){
		leftCol[i] = "";
		rightCol[i] = "";

		for(int j=0; j<5; j++){
		leftCol[i] += inLine[i][j];
		rightCol[i] += inLine[i][j+8];
		}
		leftNum[i] = std::stoi(leftCol[i]);
		rightNum[i] = std::stoi(rightCol[i]);
		cout << leftNum[i] << " " << rightNum[i] << endl;
	}

	std::sort(leftNum, leftNum + counter);
	std::sort(rightNum, rightNum + counter);
	int differences[counter];
	int totalDifference = 0;


	for(int i=0; i<counter;i++){
		differences[i] = abs(leftNum[i] - rightNum[i]);
		cout << leftNum[i] << " " << rightNum[i] << endl;
	}
	for(int i=0; i<counter;i++){
		totalDifference += differences[i];
	}
	cout << endl << "total difference: " << totalDifference << endl;	

	//input in the file and subtract the bigger from the lesser
	//next get the absolute value of these differences
	//then lastly add them together
	

	inputfile.close();
	return 0;
}
