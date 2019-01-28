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
   freopen("blist.in", "r", stdin);
    freopen("blist.out","w",stdout);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int N;
    cin>>N;
    vector<pair<pair<int,int >,int > > inp;
    vector<pair<int,int > >ad;
    vector<int> cost;

    REP(i,0,N){
    	int a,b,c;
    	cin>>a>>b>>c;
    	inp.PB({{a,i},0});
    	inp.PB({{b,i},1});
    	cost.PB(c);
    	

    }
    int use=0;	
    int av=0;
    int req=0;
    sort(inp.begin(),inp.end());
   /* for(auto d:inp){
    	cout<<"{{"<<d.F.F<<","<<d.F.S<<"},"<<d.S<<"} ";
    }
    cout<<"\n";*/
    for(int i=0;i<inp.size();i++){
    	if(inp[i].S==0){
    		if(av>=cost[inp[i].F.S]){
    			av=av-cost[inp[i].F.S];
    			use=use+cost[inp[i].F.S];
    		}
    		else{
    			req=req+cost[inp[i].F.S]-av;
    			av=cost[inp[i].F.S];
    			av=0;
    			use=+cost[inp[i].F.S];

    		}
    	}
    	else{
    		av+=cost[inp[i]	.F.S];
    		use-=cost[inp[i].F.S];
    	}
    }
    cout<<req<<"\n";

    return 0;
}