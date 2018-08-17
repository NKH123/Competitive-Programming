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
long long ans=-1;
int n,m,k;
int b[19][19];
vi a;
long long dp[1<<19][19];
long long fun(int mask,int prev)
{   if(__builtin_popcount(mask)==m){
    return 0;}
    if(dp[mask][prev]!=-1)return dp[mask][prev];
    long long ans=0;
    REP(i,0,n){
        if(!(mask&(1<<i))){
                    ans=max(ans,a[i]+fun(mask|(1<<i),i)+b[prev][i]);
        }
    }
   return dp[mask][prev]=ans;
}
int main()
{   ios::sync_with_stdio(false);
    memset(b,0,sizeof(b));
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    a.resize(n);
    REP(i,0,n)
    cin>>a[i];
    int A,B,C;
    REP(i,0,k)
    {
       cin>>A>>B>>C;
       A--;
       B--;
       b[A][B]=C;
    }
    cout<<fun(0,18);
    return 0;
}
