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
    int t;
    cin>>t;
    while(t--){
    	ll ang;
    	cin>>ang;
    	//int a=__gcd(n,180);
    	//cout<<180/a<<"\n";
    	ll i;
    	ll cm=__gcd(ang,180LL);
    	//trace(cm);
    	ll a=180/cm;
    	ll b=ang/cm;
    	//trace(a);
    	//trace(b);
    	for(i=b;i<=998244353/a;i+=b){
    	//	trace(i);
    		ll n=a*b;
    	//	trace(n);
    		if((a*i/b-2)>=(i)){

    			break;
    		}
    	}
    	cout<<a*i/b<<"\n";

    }
    return 0;	
}