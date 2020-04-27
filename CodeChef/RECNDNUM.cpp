#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

int mod=1e9;
// mod+=7;

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    mod+=7;
    while(t--){
        int n, k;
        cin>>n>>k;
        if(n==0){
            int ans=0;
            ans=(n*n)%mod;
            k--;
            int mul=(((k*(k+1))/2)%mod);
            mul=(2*mul)%mod;
            ans=(ans+mul)%mod;
            cout<<ans<<"\n";
        }
        else{
            int ans=0;
            ans=(n*n)%mod;
            int steps=(2*n)%mod;
            steps=((k/2)*2*n)%mod;
            int contr=0;
            contr=k/2;
            if(k%2==0){
                contr--;
            }
            contr=(contr*(contr+1))/2;
            contr=(2*contr)%mod;
            ans=(ans+steps)%mod;
            ans=(ans+contr)%mod;
            cout<<ans<<"\n";


        }

    }

    return 0;
}