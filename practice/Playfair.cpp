#include <iostream>
#include <string>
using namespace std;

string grid = "";

// Helper to check if a letter is already in our grid
bool alreadyExists(char c) {
    for (int i = 0; i < grid.length(); i++) {
        if (grid[i] == c) return true;
    }
    return false;
}

// Manual search for Row and Column
void findPos(char c, int &r, int &cl) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 25; i++) {
        if (grid[i] == c) {
            r = i / 5;
            cl = i % 5;
            return;
        }
    }
}

int main() {
    string key = "KEY", msg = "HELLO", alpha = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    // 1. CREATE GRID (Manual check for unique letters)
    for (int i = 0; i < key.length(); i++) {
        if (!alreadyExists(key[i])) grid += key[i];
    }
    for (int i = 0; i < alpha.length(); i++) {
        if (!alreadyExists(alpha[i])) grid += alpha[i];
    }

    // 2. PREPARE MESSAGE (Pairing)
    string p = "";
    for (int i = 0; i < msg.length(); i++) {
        p += msg[i];
        // If two letters are the same, add 'X'
        if (i + 1 < msg.length() && msg[i] == msg[i+1]) p += 'X';
    }
    if (p.length() % 2 != 0) p += 'X';

    // 3. ENCRYPT
    string cipher = "";
    for (int i = 0; i < p.length(); i += 2) {
        int r1, c1, r2, c2;
        findPos(p[i], r1, c1);
        findPos(p[i+1], r2, c2);

        if (r1 == r2) { // Same Row
            cipher += grid[r1 * 5 + (c1 + 1) % 5];
            cipher += grid[r2 * 5 + (c2 + 1) % 5];
        } else if (c1 == c2) { // Same Column
            cipher += grid[((r1 + 1) % 5) * 5 + c1];
            cipher += grid[((r2 + 1) % 5) * 5 + c2];
        } else { // Rectangle
            cipher += grid[r1 * 5 + c2];
            cipher += grid[r2 * 5 + c1];
        }
    }

    // 4. DECRYPT (Same logic, move Left/Up using +4)
    string plain = "";
    for (int i = 0; i < cipher.length(); i += 2) {
        int r1, c1, r2, c2;
        findPos(cipher[i], r1, c1);
        findPos(cipher[i+1], r2, c2);

        if (r1 == r2) {
            plain += grid[r1 * 5 + (c1 + 4) % 5];
            plain += grid[r2 * 5 + (c2 + 4) % 5];
        } else if (c1 == c2) {
            plain += grid[((r1 + 4) % 5) * 5 + c1];
            plain += grid[((r2 + 4) % 5) * 5 + c2];
        } else {
            plain += grid[r1 * 5 + c2];
            plain += grid[r2 * 5 + c1];
        }
    }

    cout << "Cipher: " << cipher << endl;
    cout << "Plain:  " << plain << endl;

    return 0;
}