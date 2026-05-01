#include <iostream>
#include <string>
using namespace std;

string grid = "";

void findPos(char c, int &r, int &cl) {
    if (c == 'J') c = 'I';
    int pos = grid.find(c);
    r = pos / 5;
    cl = pos % 5;
}

int main() {
    string key = "MONARCHY", msg = "HELLO", alpha = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    
    // 1. Build Grid (Simple Way)
    for (char c : key + alpha) {
        if (grid.find(c) == string::npos) grid += c;
    }

    // 2. Prepare Message (Add 'X' for repeats and odd length)
    string p = "";
    for (int i = 0; i < msg.length(); i++) {
        p += msg[i];
        if (i + 1 < msg.length() && msg[i] == msg[i+1]) p += 'X';
    }
    if (p.length() % 2 != 0) p += 'X';

    // 3. Encrypt using ONLY Row and Column rules
    string cipher = "";
    for (int i = 0; i < p.length(); i += 2) {
        int r1, c1, r2, c2;
        findPos(p[i], r1, c1);
        findPos(p[i+1], r2, c2);

        if (r1 == r2) { // Rule 1: Same Row (Shift Right)
            cipher += grid[r1 * 5 + (c1 + 1) % 5];
            cipher += grid[r2 * 5 + (c2 + 1) % 5];
        } 
        else if (c1 == c2) { // Rule 2: Same Column (Shift Down)
            cipher += grid[((r1 + 1) % 5) * 5 + c1];
            cipher += grid[((r2 + 1) % 5) * 5 + c2];
        } 
        else { // Rectangle case (Topic 8 implies skipping or keeping same)
            cipher += p[i]; 
            cipher += p[i+1];
        }
    }

    cout << "Grid: " << grid << endl;
    cout << "Cipher: " << cipher << endl;
    return 0;
}