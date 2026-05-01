#include <iostream>
#include <string>
using namespace std;

// Function to find (a^-1) mod 26
int getInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) return i;
    }
    return -1; // Should not happen if 'a' is coprime to 26
}

int main() {
    string msg = "SOHAM"; // Example plaintext
    int a = 5, b = 8;     // Keys
    string encrypted = "", decrypted = "";

    // --- ENCRYPTION ---
    for (char c : msg) {
        int x = c - 'A';
        int v = (a * x + b) % 26;
        encrypted += (char)(v + 'A');
    }

    // --- DECRYPTION ---
    int inv = getInverse(a);
    for (char c : encrypted) {
        int x = c - 'A';
        // Formula: inv * (x - b) mod 26
        int v = (inv * (x - b)) % 26;
        if (v < 0) v += 26; // Handling C++ negative modulo
        decrypted += (char)(v + 'A');
    }

    cout << "--- Affine Cipher Lab ---" << endl;
    cout << "Original:   " << msg << endl;
    cout << "Encrypted:  " << encrypted << endl;
    cout << "Decrypted:  " << decrypted << endl;

    return 0;
}