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
int t;
int n;
vector<char> type;
vi val;
long long ans=0;
long long dp[100005];
long long calc(int i){
    if(i>(n-1)){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    else{
            if(i==(n-1)){
                return dp[i]=val[i];
            }
        	char cur=type[i],next=type[i+1];
        	if((cur=='J'&&next=='F')||(cur=='F'&&next=='F')){
        		return dp[i]=val[i]+calc(i+1);
        	}
        	if((cur=='J'&&next=='J')||(cur=='F'&&next=='J')){
        		return dp[i]=max(val[i]+calc(i+2),calc(i+1));
        	}

    }
}

int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        ans=0;
        cin>>n;
        type.clear();
        val.clear();
        type.resize(n);
        val.resize(n);
        REP(i,0,n){
            cin>>type[i];
        }
        REP(i,0,n){
            cin>>val[i];
        }
        ans=calc(0);
        //REP(i,0,n){
          //  ans=max(ans,calc(i));
        //}
    cout<<ans<<"\n";
    }
    return 0;
}
