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
        return checkValid(x, y, i + x, j + y, text, it + 1);
    }
    if (it == 2 && text[i][j] == 'A') {
        return checkValid(x, y, i + x, j + y, text, it + 1);
    }
    if (it == 3 && text[i][j] == 'S') {
        return true; // X-M-A-S matched
    }
    return false;
}

int main() {
    ifstream inFile("puzzle_input.txt");
    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    vector<string> text;
    string line;
    while (getline(inFile, line)) {
        text.push_back(line);
    }
    inFile.close();

    

    int numValid = 0;
    for (int i = 0; i < text.size(); i++) {
        
        for (int j = 0; j < text[i].size(); j++) {
            if (text[i][j] == 'X') {
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue; // Skip no-direction case
                        if (checkValid(x, y, i, j, text, 0)) {
                            numValid++;
                        }
                    }
                }
            }
        }
    }
    cout << "Total XMAS found: " << numValid << endl;
    return 0;
}
