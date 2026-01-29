//part b question 1 advent of code
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
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
	
	inputfile.close();
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

	//make unique number list in the left column
	//search through the right column to see how many times each unique number appears
	//once looped through multiply the unique number by the amount of times it appears
	//and add to the total 
	
	int uniqNumberCount = 0;
	vector<int> uniqNumbers = {};
	bool Match = false;

	for(int i=0; i<counter;i++){
		for(auto element : uniqNumbers) {
			if(leftNum[i] == element){ Match = true; break; }
			else {}
		}
		if(!Match) {
			uniqNumbers.push_back(leftNum[i]);
		}
	}
	
	int size = uniqNumbers.size();	
	vector<int> matchNumber = {};
	int numCounter = 0;
	int totalValue = 0;

	for(int j=0;j<counter;j++){
		for(int i=0; i<size;i++){
			if(uniqNumbers.at(j) == rightNum[i]) {
				numCounter++;
			}
			else {}
		}
	matchNumber.push_back(numCounter);
	numCounter = 0;
	}
	for(int j=0; j<size;j++){
		totalValue += (matchNumber.at(j) * uniqNumbers.at(j));
	}	
	cout << "total value: " << totalValue << endl;

	return 0;
}
