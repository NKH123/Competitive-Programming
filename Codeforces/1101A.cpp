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
	int q;
	cin>>q;
	while(q--){
		ll l,r,d;
		cin>>l>>r>>d;
		ll mul;
		/*if(d==1){
			if(l>1){
				mul=1;
			}
			else{
				mul=r+1;
			}
		}
	else{
		for(int i=1;;i++){
			mul=d*i;
			if(mul <l || mul>r){
				break;
			}
		}
	}*/
		if(d>=l && d<=r){
			ll no=r/d;
			mul=d*(no+1);
		}
		else{
			mul=d;
		}
	cout<<mul<<"\n";
}

return 0;
}