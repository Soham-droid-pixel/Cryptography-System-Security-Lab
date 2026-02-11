#include<bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res=1;
    base=base%mod;
    while (exp>0) {
        if (exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp=exp/2;
    }
    return res;
}

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {
    long long p,q;
    cout<<"Enter primes p and q: ";
    cin>>p>>q;

    long long n=p*q;
    long long phi=(p-1)*(q-1);

    long long e=2;
    while (e<phi) {
        if (gcd(e,phi)==1) break;
        e++;
    }

    long long d=0;
    int k=1;
    while(1) {
        k=k+phi;
        if (k%e==0) {
            d=k/e;
            break;
        }
    }

    cout<<"Public Key: "<<e<<" "<<n<<endl;
    cout<<"Private Key: "<<d<<" " <<n<<endl;

    string msg;
    cout<<"Enter message to encrypt: ";
    cin>>msg;

    vector<long long> cipher;
    cout<<"Encrypted: ";
    for (int i=0;i<msg.length();i++) {
        long long m=msg[i];
        long long c=power(m, e, n);
        cipher.push_back(c);
        cout<<c<< " ";
    }
    cout<<endl;

    string decrypted="";
    for (int i=0;i<cipher.size();i++) {
        long long c=cipher[i];
        long long m=power(c, d, n);
        decrypted +=(char)m;
    }

    cout<<"Decrypted:"<<decrypted<<endl;

    return 0;
}