#include<bits/stdc++.h>
using namespace std;

long long gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int main(){
    long long num1=48,num2=18;
    cout<<"GCD = "<<gcd(num1,num2)<<endl;
    return 0;
}