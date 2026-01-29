//day 8

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Position{
    int x = -1;
    int y = -1;
};


int main(){

    fstream f;
    f.open("puzzle.txt");

    vector<string> lines;
    string line;
    while(getline(f, line)){
	lines.push_back(line);
    }
    //0-9, a-z, A-Z
    //ascii values 48-57, 65 - 90, 97 - 122

    vector<char> chars;

    //this was added so that I would have a list of all the possible characters
    //that represent the frequencies
    for(char c = '0'; c<= '9'; ++c){
	chars.push_back(c);
    }
    for(char c = 'A'; c<= 'Z'; ++c){
	chars.push_back(c);
    }
    for(char c = 'a'; c<= 'z'; ++c){
	chars.push_back(c);
    }

    /* for(char c : chars){
	cout << "ASCII: " << static_cast<int>(c) << "\n";
    } */

    vector<Position> currPositions;
    vector<Position> antiNodes;
    
    for(int i=0;i<chars.size();i++){
	for(int j=0;j<lines[0].size();j++){
	    for(int k=0;k<lines.size();k++){
		
		if(lines[k][j] == chars[i]){
		    Position placePosition;
		    placePosition.x = j;
		    placePosition.y = i;
		    currPositions.push_back(placePosition);
		}
	    }
	}
	
    }

    return 0;
}
