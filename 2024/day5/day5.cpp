#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    ifstream inFile;	
    inFile.open("puzzle_input.txt");


    vector<pair<int, int>> numPairs;
    vector<vector<int>> numLists;

    string line; 
    while(getline(inFile, line)){

	if(line.find("|")) {
	stringstream ss(line);
	string string1, string2;

	getline(ss, string1, '|');
	getline(ss, string2);
	
    int num1 = stoi(string1);
    int num2 = stoi(string2);
    numPairs.push_back(make_pair(num1, num2));

    else{
	stringstream ss(line);
	string numStrings;
	vector<int> numPush;
	
    }

    if(!inFile.is_open()) {
	cerr << "Could not open the file!" << endl;
	return 1;
    }

    inFile.close();
return 0;
}
