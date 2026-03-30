#include <iostream>
#include <string>
using namespace std;

// 1. Tables (Usually provided - skip memorizing these)
int pc1[] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
int pc2[] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
int shifts[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

int main() {
    string hex = "133457799BBCDFF1", bin = "";

    // A. HEX TO BINARY (The absolute easiest way)
    string hex_chars = "0123456789ABCDEF";
    string bin_values[] = {"0000","0001","0010","0011","0100","0101","0110","0111",
                           "1000","1001","1010","1011","1100","1101","1110","1111"};
    for(char c : hex) bin += bin_values[hex_chars.find(c)];

    // B. PC-1 PERMUTATION
    string k56 = "";
    for(int i=0; i<56; i++) k56 += bin[pc1[i]-1];

    // C. SPLIT INTO L AND R
    string L = k56.substr(0, 28), R = k56.substr(28);

    // D. 16 ROUNDS
    for(int i=0; i<16; i++) {
        // Circular Left Shift
        L = L.substr(shifts[i]) + L.substr(0, shifts[i]);
        R = R.substr(shifts[i]) + R.substr(0, shifts[i]);

        // PC-2 PERMUTATION
        string combined = L + R, subkey = "";
        for(int j=0; j<48; j++) subkey += combined[pc2[j]-1];

        cout << "K" << i+1 << ": " << subkey << endl;
    }
    return 0;
}