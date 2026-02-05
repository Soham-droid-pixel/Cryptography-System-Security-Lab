#include<bits/stdc++.h>
using namespace std;

int main(){
    string message="SOHAM";
    int a=5;
    int b=8;
    //Encryption
    string encrypted="";
    for(int i=0;i<message.length();i++){
        char c=message[i];
        if(c>='A'&& c<='Z'){
            int x=c-'A';
            int cipherValue=(a*x+b)%26;
            char cipherChar=cipherValue+'A';
            encrypted+=cipherChar;
        }
        else{
            encrypted+=c;
        }

    }
    cout<<"Original:"<<message<<endl;
    cout<<"Encrypted:"<<encrypted<<endl;
    //Decryption
    int a_inverse=-1;
    for(int i=1;i<=26;i++){
        if((a*i)%26==1){
            a_inverse=i;
            break;
        }
    }
    string decrypted="";
    for(int i=0;i<encrypted.length();i++){
        char c=encrypted[i];
        if(c>='A'&& c<='Z'){
            int x=c-'A';
            int val=a_inverse*(x-b);
            val=val%26;
            if(val<0){
                val=val+26;
            }
            char plainChar=val+'A';
            decrypted+=plainChar;
            
        }
        else{
                decrypted+=c;
            }
    }
    cout<<"Decrypted:"<<decrypted;
    return 0;
}