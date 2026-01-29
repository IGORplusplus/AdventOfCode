#include <iostream>
#include <fstream>
#include <regex>
#include <iterator>
#include <vector>
#include <cstdio>


using namespace std;
int main(){
   ifstream inFile;
   inFile.open("puzzle_input.txt");
   if (!inFile.is_open()) {
        cout << "Input file opening failed." << endl;
        exit(1);
   }

   string inputData;
   string dataChunk;
   while(!inFile.eof()) {
       getline(inFile, dataChunk);
       inputData += dataChunk;
   }

   inFile.close();

   regex mulRegex(R"rgx(mul\(\d+,\d+\))rgx");
   auto mulBegin = sregex_iterator(inputData.begin(), inputData.end(), mulRegex);

   vector<string> mulMatches;
   for (auto it = mulBegin; it != sregex_iterator(); it++) {
       smatch mulMatch = *it;
       mulMatches.push_back(mulMatch.str());
   }

    regex numRegex(R"rgx(\d+)rgx");
    sregex_iterator numBegin;
    int total = 0;
    for (auto vIt = mulMatches.begin(); vIt != mulMatches.end(); vIt++) {
	string mulString = data(*vIt);
	numBegin = sregex_iterator(mulString.begin(), mulString.end(), numRegex);
	for( auto sIt = numBegin; sIt != sregex_iterator(); sIt++) {
	    smatch num1 = *sIt;
	    sIt++;
	    smatch num2 = *sIt;
	    total += stoi(num1.str()) * stoi(num2.str());
	    }
    }
    cout << "Found " << distance(mulBegin, sregex_iterator()) << " occurences of mul(x, x)." << endl;
    printf("Total: %d\n", total);

    return 0;
}
