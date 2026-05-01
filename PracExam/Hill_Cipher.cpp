#include <iostream>
#include <string>

using namespace std;

int main() {
    // Topic 10: msg = "DIAL", k = {3, 3, 2, 5}
    // Topic 15: msg = "DONE", k = {5, 2, 3, 3}
    string msg = "DIAL"; 
    int k[2][2] = {{3, 3}, {2, 5}}; 
    string cipher = "";

    for (int i = 0; i < msg.length(); i += 2) {
        int p1 = msg[i] - 'A';
        int p2 = msg[i+1] - 'A';

        // Formula: C = (P * K) mod 26
        // C1 = (P1*K00 + P2*K10) % 26
        // C2 = (P1*K01 + P2*K11) % 26
        cipher += (char)(((p1 * k[0][0] + p2 * k[1][0]) % 26) + 'A');
        cipher += (char)(((p1 * k[0][1] + p2 * k[1][1]) % 26) + 'A');
    }

    cout << "Plaintext:  " << msg << endl;
    cout << "Ciphertext: " << cipher << endl;

    return 0;
}