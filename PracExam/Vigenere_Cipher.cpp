#include <iostream>
#include <string>
using namespace std;

int main() {
    string msg = "SOHAM"; // Example using user name
    string key = "KEY";   // The repeating keyword
    string encrypted = "", decrypted = "";

    // 1. Encryption: (Plaintext + Key) % 26
    for (int i = 0; i < msg.length(); i++) {
        int p = msg[i] - 'A';
        int k = key[i % key.length()] - 'A'; // The key repeats using %
        int v = (p + k) % 26;
        encrypted += (char)(v + 'A');
    }

    // 2. Decryption: (Ciphertext - Key + 26) % 26
    for (int i = 0; i < encrypted.length(); i++) {
        int c = encrypted[i] - 'A';
        int k = key[i % key.length()] - 'A';
        int v = (c - k + 26) % 26; // +26 ensures no negative results
        decrypted += (char)(v + 'A');
    }

    cout << "--- Vigenere Cipher ---" << endl;
    cout << "Original:  " << msg << endl;
    cout << "Key:       " << key << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}