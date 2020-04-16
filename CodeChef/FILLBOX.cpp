#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
vector<vector<int> >dp;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n, k, p, q;
        cin>>n>>k>>p>>q;
        dp.clear();
        dp.resize(n,vector<int>(2,0));
        if(p==q){
            dp[0][1]=1;
        }
        else{
            dp[0][0]=1;
        }
        for(int i=1;i<n;i++){
            dp[i][1]=dp[i-1][0];
            dp[i][0]=((dp[i-1][1]*(k-1) )%mod+(dp[i-1][0]*(k-2))%mod)%mod;
        }


        cout<<dp[n-1][1]<<"\n";

    }    

    return 0;
}