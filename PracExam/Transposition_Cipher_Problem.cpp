#include <iostream>
#include <string>
using namespace std;

int main() {
    string pt = "EXAM"; // Plaintext example from Topic 19
    string ct = "";
    string decrypted = "";

    // 1. ENCRYPTION
    // Rule: Even positions (2, 4...) first, then Odd positions (1, 3...)
    
    // Pick even positions (index 1, 3, 5...)
    for (int i = 1; i < pt.length(); i += 2) {
        ct += pt[i];
    }
    // Pick odd positions (index 0, 2, 4...)
    for (int i = 0; i < pt.length(); i += 2) {
        ct += pt[i];
    }

    // 2. DECRYPTION
    // To reverse it, we need to know where the odd characters start
    int mid = pt.length() / 2;
    decrypted.resize(pt.length());
    
    int evenIdx = 0;
    int oddIdx = mid;

    // Place even-positioned characters back into indices 1, 3, 5...
    for (int i = 1; i < pt.length(); i += 2) {
        decrypted[i] = ct[evenIdx++];
    }
    // Place odd-positioned characters back into indices 0, 2, 4...
    for (int i = 0; i < pt.length(); i += 2) {
        decrypted[i] = ct[oddIdx++];
    }

    cout << "--- Topic 19 Transposition ---" << endl;
    cout << "Original:   " << pt << endl;
    cout << "Ciphertext: " << ct << endl; // Should be XMEA for EXAM
    cout << "Decrypted:  " << decrypted << endl;

    return 0;
}