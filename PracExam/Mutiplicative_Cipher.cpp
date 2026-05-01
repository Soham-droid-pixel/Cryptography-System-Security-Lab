#include <iostream>
#include <string>
using namespace std;

// Need this to find the inverse for decryption
int getInverse(int a) {
    for(int i = 1; i < 26; i++) {
        if((a * i) % 26 == 1) return i;
    }
    return 1;
}

int main() {
    string msg = "SOHAM";
    int a = 5; // Multiplicative key (must be coprime to 26)
    string encrypted = "", decrypted = "";

    // Encryption: (x * a) % 26
    for(char c : msg) {
        int x = c - 'A';
        int v = (x * a) % 26;
        encrypted += (char)(v + 'A');
    }

    // Decryption: (x * inverse_a) % 26
    int inv = getInverse(a);
    for(char c : encrypted) {
        int x = c - 'A';
        int v = (x * inv) % 26;
        decrypted += (char)(v + 'A');
    }

    cout << "--- Multiplicative Cipher ---" << endl;
    cout << "Original:  " << msg << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}