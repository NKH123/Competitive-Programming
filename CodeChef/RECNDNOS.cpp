#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<int> a;
    set<int>S;
    vector<int>dp;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        for(int i=0;i<n;i++){            
            cin>>a[i];
            S.insert(a[i]);
        }
        int ans=0;
        int Ans=0;
        int Type=0;
        for(auto g:S){
            dp.clear();
            dp.resize(n);
            for(int i=0;i<n;i++){
                if(a[i]==g){
                    if(i==0 || i==1){
                        dp[i]=1;
                        ans=max(ans,1LL);
                    }
                    else{
                        dp[i]=dp[i-2]+1;
                        ans=max(ans,dp[i]);
                    }
                }
                else{
                    if(i!=0)
                        dp[i]=dp[i-1];
                    ans=max(ans,dp[i]);
                }
            }
            if(ans>Ans){
                Ans=ans;
                Type=g;
            }
        }
        cout<<Type<<"\n";
    }

    return 0;
}