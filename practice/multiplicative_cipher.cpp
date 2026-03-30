#include <bits/stdc++.h>
using namespace std;

// Find the modular inverse: (k * i) % 26 == 1
int getInverse(int k) {
    for (int i = 1; i < 26; i++) {
        if ((k * i) % 26 == 1) return i;
    }
    return -1; // If no inverse exists (invalid key)
}

int main() {
    string msg = "HELLO";
    int k = 7; // Must be coprime to 26

    // --- ENCRYPTION ---
    string encrypted = "";
    for (char c : msg) {
        int x = c - 'A';
        int v = (x * k) % 26;
        encrypted += (char)(v + 'A');
    }

    // --- DECRYPTION ---
    string decrypted = "";
    int inv = getInverse(k);
    
    if (inv == -1) {
        cout << "Invalid Key! No inverse found." << endl;
        return 0;
    }

    for (char c : encrypted) {
        int x = c - 'A';
        int v = (x * inv) % 26;
        // No need for 'v < 0' check here because we don't subtract
        decrypted += (char)(v + 'A');
    }

    cout << "Original:  " << msg << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}