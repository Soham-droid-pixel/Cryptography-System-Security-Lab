#include<bits/stdc++.h>
using namespace std;

long long power(long long base,long long exp,long long mod){
    long long res=1;
    base%=mod;
    while(exp>0){
        if(exp%2==1){
            res=(res*base)%mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int main(){
    long long p=11,q=13;
    long long n=p*q;
    long long phi=(p-1)*(q-1);

    long long e=2;
    while(e<phi){
        if(gcd(e,phi)==1){
            break;
        }
        else{
            e++;
        }
    }

    long long d=1;
    while((d*e)%phi!=1){
        d++;
    }

    cout<<"Public key (e,n):"<<e<<","<<n<<endl;
    cout<<"Private key (d,n):"<<d<<","<<n<<endl;

    string msg="HI";
    vector<long long>cipher;

    cout<<"Encrypted:";
    for(char c:msg){
        long long m=(long long)c;
        long long c_text=power(m,e,n);
        cipher.push_back(c_text);
        cout<<c_text<<" ";


    }
    cout<<endl;

    string decrypted="";
    for(long long c_text:cipher){
        long long m=power(c_text,d,n);
        decrypted+=(char)m;
    }
    cout<<"Decrypted:"<<decrypted<<endl;
    return 0;


}