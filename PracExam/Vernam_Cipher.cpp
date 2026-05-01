#include <iostream>
#include <string>
using namespace std;

int main() {
    string msg = "SOHAM"; // Plaintext
    string key = "HELLO"; // Key must be same length as msg
    string encrypted = "", decrypted = "";

    if (msg.length() != key.length()) {
        cout << "Error: Key length must match message length!" << endl;
        return 1;
    }

    // 1. Encryption: (Plaintext + Key) % 26
    for(int i = 0; i < msg.length(); i++) {
        int p = msg[i] - 'A';
        int k = key[i] - 'A';
        int v = (p + k) % 26;
        encrypted += (char)(v + 'A');
    }

    // 2. Decryption: (Ciphertext - Key) % 26
    for(int i = 0; i < encrypted.length(); i++) {
        int c = encrypted[i] - 'A';
        int k = key[i] - 'A';
        int v = (c - k) % 26;
        if(v < 0) v += 26; // Handle negative wrapping
        decrypted += (char)(v + 'A');
    }

    cout << "--- Vernam Cipher (Topic 6) ---" << endl;
    cout << "Plaintext:  " << msg << endl;
    cout << "Key:        " << key << endl;
    cout << "Ciphertext: " << encrypted << endl;
    cout << "Decrypted:  " << decrypted << endl;

    return 0;
}