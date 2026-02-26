#include <iostream>
#include <vector>
#include <string>

using namespace std;

void RC4(string SOHAM, string KALGUTKAR) {
    int n=256;
    vector<int> S(n);
    
    for(int i=0;i<n;i++) {
        S[i]=i;
    }

    int j=0;
    int key_len=KALGUTKAR.length();
    for(int i=0;i<n;i++) {
        j=(j+S[i]+(unsigned char)KALGUTKAR[i%key_len])%n;
        int temp=S[i];
        S[i]=S[j];
        S[j]=temp;
    }

    int i=0;
    j=0;
    cout<<"EncryptedOutput:";

    for(int k=0;k<SOHAM.length();k++) {
        i=(i+1)%n;
        j=(j+S[i])%n;
        
        int temp=S[i];
        S[i]=S[j];
        S[j]=temp;
        
        int t=(S[i]+S[j])%n;
        int keystream_byte=S[t];

        unsigned char cipher_char=(unsigned char)(SOHAM[k]^keystream_byte);
        
        printf("%02x", cipher_char);
    }
    cout<<endl;
}

int main() {
    string my_data="SOHAM_IS_CODING"; 
    string my_key="KALGUTKAR_KEY";

    cout<<"Plaintext:"<<my_data<<endl;
    RC4(my_data,my_key);

    return 0;
}