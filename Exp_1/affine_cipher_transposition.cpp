#include <bits/stdc++.h>
using namespace std;

int main() {
    string msg = "SOHAM";
    int a = 5;
    int b = 8;
    int k = 2;

    string s1 = "";
    for(int i = 0; i < msg.length(); i++) {
        if(msg[i] >= 'A' && msg[i] <= 'Z') {
            int x = msg[i] - 'A';
            int v = (a * x + b) % 26;
            s1 += (char)(v + 'A');
        } else {
            s1 += msg[i];
        }
    }

    while(s1.length() % k != 0) {
        s1 += 'X';
    }

    string s2 = "";
    int rows = s1.length() / k;

    for(int j = 0; j < k; j++) {
        for(int i = 0; i < rows; i++) {
            int idx = i * k + j;
            s2 += s1[idx];
        }
    }

    cout << "Original: " << msg << endl;
    cout << "Affine: " << s1 << endl;
    cout << "Final: " << s2 << endl;

    string s3 = "";
    char grid[rows][k];
    int idx = 0;

    for(int j = 0; j < k; j++) {
        for(int i = 0; i < rows; i++) {
            grid[i][j] = s2[idx++];
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < k; j++) {
            s3 += grid[i][j];
        }
    }

    int inv = -1;
    for(int i = 1; i <= 26; i++) {
        if((a * i) % 26 == 1) {
            inv = i;
            break;
        }
    }

    string finalDec = "";
    for(int i = 0; i < s3.length(); i++) {
        if(s3[i] >= 'A' && s3[i] <= 'Z') {
            int x = s3[i] - 'A';
            int v = inv * (x - b);
            v = v % 26;
            if(v < 0) v += 26;
            finalDec += (char)(v + 'A');
        } else {
            finalDec += s3[i];
        }
    }

    cout << "Decrypted Step 1: " << s3 << endl;
    cout << "Final Decrypted: " << finalDec << endl;

    return 0;
}