#include<bits/stdc++.h>
using namespace std;

long long power(long long base,long long exp,long long mod){
    long long res=1;
    base%=mod;
    while(exp>0){
        if(exp%2==1)res=(res*base)%mod;
        base=(base*base)%mod;
        exp=exp/2;
    }
    return res;
}

int main(){
    long long P=23;
    long long G=5;
    long long a=6;
    long long b=15;

    long long x=power(G,a,P);
    long long y=power(G,b,P);

    long long Ka=power(y,a,P);
    long long Kb=power(x,b,P);

    cout << "Publicly Shared P: " << P << ", G: " << G << endl;
    cout << "Alice's Public Key (x): " << x << endl;
    cout << "Bob's Public Key (y): " << y << endl;
    cout << "------------------------------" << endl;
    cout << "Alice's Shared Secret: " << Ka << endl;
    cout << "Bob's Shared Secret: " << Kb << endl;

    if(Ka==Kb){
        cout << "\nSuccess! Shared Secret Key: " << Ka << endl;
    }

    return 0;
}