#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    //freopen("b.in","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=(1L)<<((n/26));
        int N=n%26;
        if(n%26==0){
            ans=ans>>1;
        }
        if(n==0 || (N<=2 && N>0)){
            cout<<ans<<" "<<0<<" "<<0<<"\n";
        }
        else if(N>2 && N<=10){
            cout<<0<<" "<<ans<<" "<<0<<"\n";
        }
        else if(N==0 || (N>10 && N<=25) ){
            cout<<0<<" "<<0<<" "<<ans<<"\n";
        }
    }
    return 0;
}