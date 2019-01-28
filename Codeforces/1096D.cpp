#include<bits/stdc++.h>
using namespace std;

long long dp[100005][5];
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	s='.'+s;
	dp[0][0]=0;
	vector<long long> a;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='h'){
			dp[i][1]=dp[i-1][1]+a[i];
		}
		else{
			dp[i][1]=dp[i-1][1];
		}
	}
	string t=".hard";
	for(int i=1;i<=n;i++){
		for(int j=2;j<=4;j++){
			if(s[i]==t[j]){
				dp[i][j]=min(dp[i-1][j]+a[i],dp[i][j-1]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	/*for(int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	cout<<dp[n][4]<<"\n";
	return 0;

}