#include <iostream>
#include <string>
using namespace std;

int main() {
    string msg = "SOHAM";
    int k = 3; // Shift key (Additive key)
    string encrypted = "", decrypted = "";

    // Encryption: (x + k) % 26
    for(char c : msg) {
        int x = c - 'A';
        int v = (x + k) % 26;
        encrypted += (char)(v + 'A');
    }

    // Decryption: (x - k) % 26
    for(char c : encrypted) {
        int x = c - 'A';
        int v = (x - k) % 26;
        if(v < 0) v += 26; // Handling negative result
        decrypted += (char)(v + 'A');
    }

    cout << "--- Additive Cipher ---" << endl;
    cout << "Original:  " << msg << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}