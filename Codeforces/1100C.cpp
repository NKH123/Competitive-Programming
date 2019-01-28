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
    int n,r;
    cin>>n>>r;
    double a=(double)r*(double)sin(3.14159265358979/(1.0*n) )/(1-(double)sin(3.14159265358979/(1.0*n) ));
   // trace((1-(double)sin(3.141592/2.0*n)));
    //trace((double)sin(3.141592/(2*n)));
    //trace(3.141592/2*n)
    //cout<<(1-sin(3.14159265358979/2.0*n))<<"\n";
   // cout<<(double)sin(3.141592/6)<<"\n";
    printf("%.9f\n",a);
    return 0;
}