#include<bits/stdc++.h>
using namespace std;

int getInverse(int a){
    for(int i=1;i<26;i++){
        if((a*i)%26==1){
            return i;
        }

    }
    return 1;
}
int main(){
string msg="SOHAM";
int a=5,b=8,k=2;
string decrypted="";

string s1="";
for(char c:msg){
    int x=c-'A';
    int v=(a*x+b)%26;
    s1+=(char)(v+'A');
}

while(s1.length()%k!=0){
    s1+='X';
}

string s2="";
int rows=s1.length()/k;
for(int j=0;j<k;j++){
    for(int i=0;i<rows;i++){
        s2+=s1[i*k+j];
    }
}
string s3=s1;
int idx=0;
for(int j=0;j<k;j++){
    for(int i=0;i<rows;i++){
        s3[i*k+j]=s2[idx++];
    }
}
int inv=getInverse(a);
for(char c:s3){
    int x=c-'A';
    int v=(inv*(x-b))%26;
    if(v<0){
        v+=26;
    }
    decrypted+=(char)(v+'A');
}

cout<<"Original:"<<msg<<endl;
cout<<"Encrypted:"<<s2<<endl;
cout<<"Decrypted:"<<decrypted<<endl;
return 0;

}