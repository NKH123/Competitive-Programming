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
    int n;
    cin>>n;
    vi a;
    a.resize(n);
    REP(i,1,n+1){
    	cin>>a[i];
    }
    vi b;
    b.resize(n);
    REP(i,1,n+1){
    	b[i]=a[i%(n+1)]^a[(i+1)%(n+1)]^a[(i+2)%(n+1)==0?1:];


    }
    for(int i=1;i<=n;i++){
    	cout<<b[i]<<" ";
    }
    cout<<"\n";

    while(1){
    	int N;
    	cin>>N;
    	vi c;
    	c.resize(N);
    	REP(i,0,N){
    		cin>>c[i];
    	}
    	int ans=0;
    	REP(i,0,N){
    		ans=ans^b[c[i]];
    	}
    	cout<<"ans="<<ans<<"\n";

    }


    return 0;
}