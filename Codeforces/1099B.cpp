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
ll ans=0;
void fun(int n){
	if(n<=0)return;
	ans+=2*(floor(sqrt(n)));
	fun(n-((floor(sqrt(n)))*(floor(sqrt(n)))));
}

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    ll n;
    cin>>n;
   ll a,b;
    ll A,B;
    ll maxi=9+(1e9);
    for(ll i=1;i*i<=n;i++){
    	if(n%i==0){
    		a=i;
    		b=n/i;
    		if((a+b)<maxi){
    			maxi=a+b;

    		}

    	}
    }
    //fun(n);
    cout<<maxi<<"\n";
    //cout<<ans<<"\n";
    return 0;
}