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
ll nC3(ll n){
	if(n<3){
		return 0;
	}
	else{
		ll ret=1;
		ret=n*(n-1)*(n-2);
		ret=ret/6;
		return ret;
	}

}
vi adj[2005];
int main()
{   ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	
	/*set<pair<int, int > > bb;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			bb.insert({i,j});
		}
	}
	trace(bb.size());
	ll ct=0;
	while(m--){
		int A,B;
		cin>>A>>B;
		
		if(A>B)swap(A,B);
		bb.erase({A,B});
		ct++;
	}
	trace(ct);
	trace(bb.size());
	ll tot=n*(n-1);
	tot=tot/2;
	ll a=nC3(bb.size());
	ll b=nC3(tot-bb.size());
	cout<<a+b<<"\n";*/
	while(m--){
		int A,B;
		cin>>A>>B;
		adj[A].PB(B);
		adj[B].PB(A);

	}
	ll tot=n*(n-1)*(n-2);
	tot=tot/6;
    if(tot<=0){
    	cout<<0<<"\n";
    	return 0;
    }
    else{
    	ll tot1=0;
    	for(int i=1;i<=n;i++){
    		tot1=tot1+(adj[i].size())*(n-1-adj[i].size());
    	}
    	trace(tot);
    	trace(tot1);
    	cout<<tot-tot1<<"\n";
    }
    return 0;
}