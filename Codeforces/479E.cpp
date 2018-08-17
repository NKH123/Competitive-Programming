#include<bits/stdc++.h>
using namespace std;
#define llp 1000000007
int n,a,b,k;
unsigned dp[5002][5002];
unsigned  pre[5002][5002];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>a>>b>>k;
    memset(dp,0,sizeof(dp));
    memset(pre,0,sizeof(pre));
    int j, maxi;
    for(int i=1; i<=k;i++)
    {
        if(a>b){j=b+1;
        maxi=n;}
        else {j=1;
        maxi=b-1;}
        for(; j<=maxi;j++)
        {
            int lo=max(1,j-abs(b-j)+1);
            int hi=min(n,j+abs(j-b)-1);
            if(i==1){
            dp[j][i]=(hi-lo);
            pre[j][i]=(dp[j][i]%llp+pre[j-1][i]%llp)%llp;
           }
           else{
            dp[j][i]=(2*llp+pre[hi][i-1]-pre[lo-1][i-1]-dp[j][i-1])%llp;
            pre[j][i]=(dp[j][i]%llp+pre[j-1][i]%llp)%llp;
           }
        }
    }
    cout<<dp[a][k]<<"\n";
    return 0;
}
