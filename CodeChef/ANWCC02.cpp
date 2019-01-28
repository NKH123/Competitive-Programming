#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
#define llp 1000000007
#define mod 1000000007


ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n,m;
    cin>>n>>m;
    vi a;
    a.resize(n);
    b.resize(m);
    ll ans=0;
    REP(i,0,n)cin>>a[i];
    REP(i,0,m)cin>>b[i];
    for(int i=0;i<m;i++){
    	ans+=a[i]*b[i];
    }
    ll ANS=0;
    for(int i=1;i<(n-m);i++){
    	ANS=ans-a[i-1]*b[0]+a[i+m]*
    }

    return 0;
}