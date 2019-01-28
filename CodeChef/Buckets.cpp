#include<bits/stdc++.h>
using namespace std;
double dp[1005][1005];
vector<int>a[1000];
int sum[1005];
int main(){
	memset(sum,0,sizeof(sum));
	memset(dp,0,sizeof(dp));
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int S;
			cin>>S;
			a[i].push_back(S);
			sum[i]+=S;

		}
	}
	if(n==1){
		for(int i=0;i<k;i++){
			cout<<(double)a[0][i]/sum[0]<<" ";
		}
		cout<<"\n";
		
	}

	else{
		for(int j=0;j<k;j++){
			dp[0][j]=(double)a[0][j]/sum[0];
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<k;j++){
				dp[i][j]=(dp[i-1][j]*(1+a[i][j])/(sum[i]+1))+(1-dp[i-1][j])*(a[i][j])/(sum[i]+1);
			}
		}
		for(int i=0;i<k;i++){
			cout<<dp[n-1][i]<<" ";
		}
		cout<<"\n";
	}

return 0;
}