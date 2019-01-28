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
    int t;
    cin>>t;
    vl a;
    vl b;
    while(t--){
    	int n;
    	cin>>n;
    	a.resize(n);
    	b.resize(n);
    	REP(i,0,n)cin>>a[i];
    	REP(i,0,n)cin>>b[i];
    	if(a[0]!=0 || b[n-1]!=0 || a[n-1]!=b[0]){
    		cout<<"No\n";
    		continue;
    	}
    	ll sum=a[n-1];
    	int f=1;
    	for(int i=1;i<(n-1);i++){
    		if(((a[i]+b[i])<sum)|| (a[i]<=0 || b[i]<=0 || a[i]>(sum+b[i]) || b[i]>(sum+a[i]))){
    			cout<<"No\n";
    			f=0;
    			break;
    		}

    	}
    	if(!f)continue;
    	else{
    		cout<<"Yes\n";
    	}
    }
    return 0;
}