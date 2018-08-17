#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int n;
vector<char> c;
char C;
int dp[5005][5005];
int sum[5005][5005];
int main()
{   ios::sync_with_stdio(false);
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    cin>>n;
    REP(i,0,n){
        cin>>C;
        c.PB(C);
    }
    dp[0][0]=1;
    sum[0][0]=1;
    int maxi=0;
    if(c[0]=='f')maxi++;
    REP(i,1,n){
        if(c[i-1]=='s'){      
            for(int j=0;j<=maxi;j++){
               if(j==0){
                dp[i][j]=sum[i-1][maxi]%llp;
                sum[i][j]=dp[i][j]%llp;
               }
               else{
                dp[i][j]=(llp+sum[i-1][maxi]%llp-sum[i-1][j-1]%llp)%llp;
                sum[i][j]=(sum[i][j-1]%llp+dp[i][j]%llp)%llp;
               }  
            }
        }
        if(c[i-1]=='f'){
             for(int j=1;j<=maxi;j++)
            {
                dp[i][j]=dp[i-1][j-1]%llp;
                sum[i][j]=(sum[i][j-1]%llp+dp[i][j]%llp)%llp;
            }
        }
        if(c[i]=='f'){
            maxi=maxi+1;       
        }
    }
    int ans=0;
    REP(i,0,maxi+1){
        ans=(ans%llp+dp[n-1][i]%llp)%llp;
    }
    cout<<ans<<"\n";
    return 0;
}
