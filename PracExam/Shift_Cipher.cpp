#include <iostream>
#include <string>
using namespace std;

int main() {
    string msg = "SOHAM"; // Your name from the summary
    int key = 3; 
    string encrypted = "", decrypted = "";

    // 1. Encryption: (x + k) % 26
    for(char c : msg) {
        int x = c - 'A';
        int v = (x + key) % 26;
        encrypted += (char)(v + 'A');
    }

    // 2. Decryption: (x - k) % 26
    for(char c : encrypted) {
        int x = c - 'A';
        int v = (x - key) % 26;
        if(v < 0) v += 26; // Wrapping around if negative
        decrypted += (char)(v + 'A');
    }

    cout << "Shift Cipher (Key=" << key << ")" << endl;
    cout << "Original:  " << msg << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}