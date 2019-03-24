#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define llp 1000000007
#define mod 1000000007

int dp[110][4][4];

int get(int i, int j){
  if(i==0 && j==1){
    return 0;
}
if(i==0 && j==2){
    return 1;
}
if(i==1 && j==0){
    return 2;
}
}
bool check(int i, int j){
    if(i==0 && j==1){
        return true;
    }
    if(i==0 && j==2){
        return true;
    }
    if(i==1 && j==0){
        return true;
    }
    return false;
}
int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    if(n==1){
        cout<<4<<"\n";
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            dp[2][i][j]=1;
        }
    }
    for(int k=3;k<=100;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(!check(i,j)){
                    for(int J=0;J<4;J++){
                        dp[k][j][J]=(dp[k][j][J]+dp[k-1][i][j])%mod;
                    }
                }
                else{
                    int Case=get(i,j);
                    if(Case==0){
                        for(int J=0;J<4;J++){
                            if(J!=2)
                                dp[k][j][J]=(dp[k][j][J]+dp[k-1][i][j])%mod;
                        }
                    }
                    if(Case==1){
                        for(int J=0;J<4;J++){
                            if(J!=1)
                                dp[k][j][J]=(dp[k][j][J]+dp[k-1][i][j])%mod;
                        }
                    }
                    if(Case==2){
                        for(int J=0;J<4;J++){
                            if(J!=2)
                                dp[k][j][J]=(dp[k][j][J]+dp[k-1][i][j])%mod;
                        }
                    }
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sum=(sum+dp[n][i][j])%mod;
        }
    }
    cout<<sum<<"\n";
    return 0;
}