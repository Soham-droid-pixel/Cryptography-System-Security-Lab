#include<iostream>
using namespace std;

long long power(long long base,long long exp,long long mod){
long long r=1;
for(int i=0;i<exp;i++){
r=(r*base)%mod;
}
return r;
}
int main(){
long long P=23;//public key
long long G=5;//public key
long long a=6;//private key
long long b=15;//private key
long long x=power(G,a,P);
long long y=power(G,b,P);
long long Ka=power(y,a,P);
long long Kb=power(x,b,P);
cout<<"P:"<<P<<" G:"<<G<<endl;
cout<<"Alice_X:"<<x<<endl;
cout<<"Bob_Y:"<<y<<endl;
cout<<"Alice_Key:"<<Ka<<endl;
cout<<"Bob_Key:"<<Kb<<endl;
if(Ka==Kb){
    cout<<"Successful key is created.";
}
return 0;
}