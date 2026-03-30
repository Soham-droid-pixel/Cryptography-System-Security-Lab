#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=7,b=4;
    int original_mod=a;

    int x_n_minus_2=1,x_n_minus_1=0;
    int y_n_minus_2=0,y_n_minus_1=1;
    int x_n,y_n;

    while(b!=0){
        int q_n=a/b;
        int r_n=a%b;

        x_n=x_n_minus_2-q_n*x_n_minus_1;
        y_n=y_n_minus_2-q_n*y_n_minus_1;

        a=b;
        b=r_n;

        x_n_minus_2=x_n_minus_1;
        x_n_minus_1=x_n;

        y_n_minus_2=y_n_minus_1;
        y_n_minus_1=y_n;
    }
    int ans=y_n_minus_2;
    if(ans<0){
        ans=ans+original_mod;
    }
    cout<<"Modular inverse is : "<<ans<<endl;
    return 0;
}