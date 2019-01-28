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
    int n,k;
    cin>>n>>k;
    vi a;
    a.resize(n);
    REP(i,0,n){
    	cin>>a[i];
    }
    int ans=-1;
    int bb[1000];
    for(int b=0;b<n;b++){
    	memset(bb,0,sizeof(bb));
    	int istart=-(b/k);

    	int e=0,s=0;
    	for(int i=(istart);(b+i*k<n);i++){
    		bb[b+i*k]=1;
    	}
    	for(int i=0;i<n;i++){
    		if(a[i]==1){
    			if(!bb[i])e++;
    		}

    		if(a[i]==(-1)){
    			if(!bb[i])s++;
    		}
    	}
    	ans=max(ans,abs(e-s));
    }
    cout<<ans<<"\n";
    return 0;
}