#include <bits/stdc++.h>
using namespace std;

// Find modular inverse of 'a' (a * i % 26 == 1)
int getInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) return i;
    }
    return -1;
}

int main() {
    string msg = "SOHAM";
    int a = 5, b = 8; // 'a' must be coprime to 26

    // --- ENCRYPTION ---
    string encrypted = "";
    for (char c : msg) {
        int x = c - 'A';
        int v = (a * x + b) % 26;
        encrypted += (char)(v + 'A');
    }

    // --- DECRYPTION ---
    string decrypted = "";
    int inv = getInverse(a);
    
    if (inv == -1) {
        cout << "Invalid Key 'a'! No inverse exists." << endl;
        return 0;
    }

    for (char c : encrypted) {
        int x = c - 'A';
        // Formula: inv * (x - b)
        int v = (inv * (x - b)) % 26;
        
        // IMPORTANT: Handle negative results for (x - b)
        if (v < 0) v += 26; 
        
        decrypted += (char)(v + 'A');
    }

    cout << "Original:  " << msg << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}