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
    vector<pair<ll,int> >a;
    vector<pair<ll,int> >b;
    a.resize(n);
    b.resize(m);

    REP(i,0,n){
    	int A;
    	cin>>A;
    	a[i]={A,i};
    }
    REP(i,0,m){
    	int A;
    	cin>>A;
    	b[i]={A,i};
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<pair<int,int> >aa;
    for(int i=0;i<n;i++){
    	aa.PB({a[i].S,b[0].S});

    }
    for(int i=m-1;i>0;i--){
    	aa.PB({a[n-1].S,b[i].S});
    }
    for(auto g:aa){
    	cout<<g.F<<" "<<g.S<<"\n";
    }
    
    return 0;
}