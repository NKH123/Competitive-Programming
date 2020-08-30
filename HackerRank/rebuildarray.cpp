#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    int n, m, k;
    cin>>n>>m>>k;
    int dp[n+5][m+5][k+5];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++) {
    	dp[0][i][0]=1;
    } 
    for(int i=1; i<n;i++) {
    	for(int j=1; j<=m; j++) {
    		//  j is already maximum
    		for(int cost = 0; cost <=k; cost++) {
    			dp[i][j][cost] +=(dp[i-1][j][cost]*j);
    		}

    		// setting j as maximum
    		for(int K = 1; K < j; K++) {
    			for(int cost = 0; cost <k; cost++) {
    				dp[i][j][cost + 1] +=(dp[i-1][K][cost]);
    			}
    		}
    	}
    }
    int ans = 0;
    for(int j=1; j<=m;j++) {
    	ans += (dp[n-1][j][k]);
    }
    cout<<ans<<"\n";

    return 0;
}