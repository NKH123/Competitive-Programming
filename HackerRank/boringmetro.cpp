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
    vl a;
    while(t--){
    	int n;
    	cin>>n;
    	a.resize(n);
    	REP(i,0,n){
    		cin>>a[i];
    	}
    	int ans=2;
    	int drop=0;
    	for(int i=0;i<a.size()-1;i++){
    		if(a[i]>=a[i+1]){
    			drop=1;
    		}
    		if(drop==1){
    			if(a[i]<a[i+1]){
    				ans++;
    				drop=0;
    			}
    		}
    	}
    	cout<<ans<<"\n";
    }
    
    return 0;
}