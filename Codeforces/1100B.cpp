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
    vi a(m);
    REP(i,0,m)cin>>a[i];
    int b[n+1];
    memset(b,0,sizeof(b));
    set<int>s;
    int k=1;
    REP(i,0,m){
    	s.insert(a[i]);
    	b[a[i]]++;
    	if(s.size()==n){
    		cout<<1;
    		for(int j=1;j<=n;j++){
    			if(b[j]==k){
    				s.erase(s.find(j));
    			}
    		}
    		//s.clear();
    		k++;
    	}
    	else{
    		cout<<0;
    	}
    }
    cout<<"\n";
    return 0;
}