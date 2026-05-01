#include <iostream>
#include <string>

using namespace std;

int main() {
    string originalMsg = "SOHAM"; 
    
    // ==========================================
    // TOPIC 16: SIMPLE COLUMNAR (4 COLUMNS)
    // ==========================================
    string msg16 = originalMsg;
    int cols16 = 4;

    // 1. Padding
    while (msg16.length() % cols16 != 0) {
        msg16 += 'X';
    }
    int rows16 = msg16.length() / cols16;

    // 2. Encryption
    string cipher16 = "";
    for (int j = 0; j < cols16; j++) {
        for (int i = 0; i < rows16; i++) {
            cipher16 += msg16[i * cols16 + j];
        }
    }

    // 3. Decryption
    string plain16 = msg16;
    int k16 = 0;
    for (int j = 0; j < cols16; j++) {
        for (int i = 0; i < rows16; i++) {
            plain16[i * cols16 + j] = cipher16[k16++];
        }
    }

    cout << "--- Topic 16 (4 Columns) ---" << endl;
    cout << "Encrypted: " << cipher16 << endl;
    cout << "Decrypted: " << plain16 << "\n" << endl;


    // ==========================================
    // TOPIC 17: SIMPLE COLUMNAR (3 COLUMNS)
    // ==========================================
    string msg17 = originalMsg;
    int cols17 = 3;

    // 1. Padding
    while (msg17.length() % cols17 != 0) {
        msg17 += 'X';
    }
    int rows17 = msg17.length() / cols17;

    // 2. Encryption
    string cipher17 = "";
    for (int j = 0; j < cols17; j++) {
        for (int i = 0; i < rows17; i++) {
            cipher17 += msg17[i * cols17 + j];
        }
    }

    // 3. Decryption
    string plain17 = msg17;
    int k17 = 0;
    for (int j = 0; j < cols17; j++) {
        for (int i = 0; i < rows17; i++) {
            plain17[i * cols17 + j] = cipher17[k17++];
        }
    }

    cout << "--- Topic 17 (3 Columns) ---" << endl;
    cout << "Encrypted: " << cipher17 << endl;
    cout << "Decrypted: " << plain17 << endl;

    return 0;
}