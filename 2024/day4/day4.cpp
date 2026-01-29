#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

bool checkValid(int x, int y, int i, int j, const vector<string>& text, int it) {
    if (i < 0 || j < 0 || i >= text.size() || j >= text[i].size()) {
        return false;
    }
    if (it == 0 && text[i][j] == 'X') {
        return checkValid(x, y, i + x, j + y, text, it + 1);
    }
    if (it == 1 && text[i][j] == 'M') {
	cout << "M";
        return checkValid(x, y, i + x, j + y, text, it + 1);
    }
    if (it == 2 && text[i][j] == 'A') {
	cout << 'A';
        return checkValid(x, y, i + x, j + y, text, it + 1);
    }
    if (it == 3 && text[i][j] == 'S') {
	cout << 'S' << endl;
        return true; // X-M-A-S matched
    }
    return false;
}

//word search is 140 by 140
int main(){

    ifstream inFile;
    inFile.open("puzzle_input.txt");
	
    int numValid = 0;
    string line;
    vector<string> text;
    while (getline(inFile, line)) {
	text.push_back(line);
    }
    
   inFile.close();
    int instance = 0; 
    int pos = 0;
    string XMAS = "XMAS";
   for (int i=0; i<text.size(); i++) {
      for(int j=0; j<text[i].size(); j++) {
	if (text[i][j] == 'X'){
		cout << text[i][j];

	   for(int x = -1;x<=1;x++){
		for(int y = -1; y<=1;y++){
		
			if(x == 0 && y == 0){}
			else{
			    int it = 1;
			    if(checkValid(x,y,i,j,text,0)){numValid++;}
			}
		}
	   }
	}
	else{}
      }
    cout << endl;
   }
   cout << numValid << endl;
   return 0;

}
