#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pc1_table[] = {
    57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
};

int pc2_table[] = {
    14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};

int shift_schedule[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

string permute(string input, int* table, int table_size) {
    string output = "";
    for (int i = 0; i < table_size; i++) {
        output += input[table[i] - 1];
    }
    return output;
}

string left_shift(string part, int n) {
    return part.substr(n) + part.substr(0, n);
}

string hexToBin(string hex) {
    string bin = "";
    for (char c : hex) {
        switch (toupper(c)) {
            case '0': bin += "0000"; break; case '1': bin += "0001"; break;
            case '2': bin += "0010"; break; case '3': bin += "0011"; break;
            case '4': bin += "0100"; break; case '5': bin += "0101"; break;
            case '6': bin += "0110"; break; case '7': bin += "0111"; break;
            case '8': bin += "1000"; break; case '9': bin += "1001"; break;
            case 'A': bin += "1010"; break; case 'B': bin += "1011"; break;
            case 'C': bin += "1100"; break; case 'D': bin += "1101"; break;
            case 'E': bin += "1110"; break; case 'F': bin += "1111"; break;
        }
    }
    return bin;
}

int main() {
    string hex_key;
    cout << "Enter 16-char Hex Key: ";
    cin >> hex_key;

    string binary_key = hexToBin(hex_key);
    string key_56bit = permute(binary_key, pc1_table, 56);

    string L = key_56bit.substr(0, 28);
    string R = key_56bit.substr(28, 28);

    for (int i = 0; i < 16; i++) {
        L = left_shift(L, shift_schedule[i]);
        R = left_shift(R, shift_schedule[i]);

        string subkey = permute(L + R, pc2_table, 48);

        cout << "K" << (i + 1) << ": " << subkey << endl;
    }

    return 0;
}