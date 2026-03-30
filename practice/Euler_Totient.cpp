#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int res=n;

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res=res-res/i;
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n>1){
        res=res-res/n;
    }
    cout<<res<<endl;
    return 0;
}