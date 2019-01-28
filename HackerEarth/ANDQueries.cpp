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
    freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n;
    cin>>n;
    vi a;
    a.resize(n);
    REP(i,0,n){
    	cin>>a[i];
    }
    int m;
    cin>>m;
    while(m--){
    	int l,r,x;
    	cin>>l>>r>>x;
    	l--;
    	r--;
    	ll ans=0;
    	for(int i=l;i<=r;i++){
    		for(int j=l;j<=r;j++){
    			for(int k=l;k<=r;k++){
    				//trace(i);
    				//trace(j);
    				//trace(k);
    				if((a[i]&a[j]&a[k])==x){
    				//s	cout<<"I'm here\n";
    					ans++;
    					ans=ans%llp;
    				}
    			}
    		}
    	}
    	cout<<ans<<"\n";
    }
    
    return 0;
}