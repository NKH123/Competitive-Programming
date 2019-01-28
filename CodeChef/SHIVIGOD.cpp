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
vl aa;
vl ps;
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;

    while(t--){
    	int n,a,b;
    	cin>>n>>b>>a;
    	aa.resize(n);
    	ps.resize(n);
    	REP(i,0,n){cin>>aa[i];
    		if(i==0){
    			ps[i]=aa[i];
    		}
    		else{
    			ps[i]=ps[i-1]+aa[i];
    		}
    	}
    	double ans=-1;
    	for(int i=a;i<=b;i++){
    		
    		for(int j=0;j<=(n-i);j++){
    			
    			if(j!=0)
    			ans=max(ans,(double(ps[j+i-1]-ps[j-1])/(double)(i)));
    			else{
    				ans=max(ans,(double(ps[j+i-1])/(double)(i)));
    			}
    			
    		}
    	}
    	//cout<<ans<<"\n";
    	printf("%.7f\n",ans);
    }

    
    return 0;
}