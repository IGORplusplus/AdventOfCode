#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int main() {
    ifstream inputFile;
    inputFile.open("puzzle_input.txt");    
    string line;

    vector<string> stringData;

    while(getline(inputFile, line)){
	stringData.push_back(line);
    }
    inputFile.close();
    
    vector<int> Data;

    for(int i=0; i<stringData.size();i++) {
    line = stringData.at(i);
    int DataTemp;
    DataTemp = stoi(line);
    Data.push_back(DataTemp);
    }

    int numTimesIncreased = 0;
    for(int i=1; i<Data.size();i++) {
	if(Data.at(i) > Data.at(i-1)){
	numTimesIncreased++;
	}
    }
    cout << numTimesIncreased << endl;

    return 0;
}
