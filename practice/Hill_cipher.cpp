#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function for modular inverse (from our previous lessons!)
int getInverse(int n) {
    n %= 26;
    for (int x = 1; x < 26; x++) {
        if ((n * x) % 26 == 1) return x;
    }
    return -1;
}

int main() {
    string msg = "HELP"; // Length must be even for 2x2
    int k[2][2] = {{3, 3}, {2, 5}}; // The Key Matrix

    // --- ENCRYPTION ---
    string cipher = "";
    for (int i = 0; i < msg.length(); i += 2) {
        int p1 = msg[i] - 'A';
        int p2 = msg[i+1] - 'A';

        // Multiply: C = P * K
        cipher += (char)(((k[0][0] * p1 + k[1][0] * p2) % 26) + 'A');
        cipher += (char)(((k[0][1] * p1 + k[1][1] * p2) % 26) + 'A');
    }
    cout << "Encrypted: " << cipher << endl;

    // --- DECRYPTION ---
    // 1. Find Determinant (ad - bc)
    int det = (k[0][0] * k[1][1] - k[0][1] * k[1][0]) % 26;
    if (det < 0) det += 26;

    // 2. Find Inverse of Determinant
    int invDet = getInverse(det);

    // 3. Find Inverse Matrix (Adjugate * invDet)
    int invK[2][2];
    invK[0][0] = (k[1][1] * invDet) % 26;          // d * invDet
    invK[0][1] = (-k[0][1] * invDet) % 26;         // -b * invDet
    invK[1][0] = (-k[1][0] * invDet) % 26;         // -c * invDet
    invK[1][1] = (k[0][0] * invDet) % 26;          // a * invDet

    // Fix negative values
    for(int i=0; i<2; i++) 
        for(int j=0; j<2; j++) 
            if(invK[i][j] < 0) invK[i][j] += 26;

    // 4. Decrypt using Inverse Matrix
    string plain = "";
    for (int i = 0; i < cipher.length(); i += 2) {
        int c1 = cipher[i] - 'A';
        int c2 = cipher[i+1] - 'A';

        plain += (char)(((invK[0][0] * c1 + invK[1][0] * c2) % 26) + 'A');
        plain += (char)(((invK[0][1] * c1 + invK[1][1] * c2) % 26) + 'A');
    }

    cout << "Decrypted: " << plain << endl;

    return 0;
}