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
int A[1005][1005];
vector<pair<int,int> >path;
int main()
{   ios::sync_with_stdio(false);
    freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> >pts(2*m);
    //int A[1005][1005];
	REP(i,0,2*m){
		int a,b;
		cin>>a>>b;
		//a--;
		//b--;
		//trace(a);
		//trace(b);
		pts[i].F=a;
		pts[i].S=b;
	}
	REP(i,0,n){
		REP(j,0,n){
			cin>>A[i][j];
		}
	}
	sort(pts.begin(),pts.end());
	for(int i=0;i<2*m;i=i+2){
		path.clear();
		//cout<<"from "<<pts[i].F<<" "<<pts[i].S<<" to "<<pts[i+1].F<<" "<<pts[i+1].S<<"\n";
		int f=0;
		for(int j=pts[i].S;j<=pts[i+1].S;j++){
			path.PB({pts[i].F,j});
			if(pts[i].F==pts[i+1].F && j==pts[i+1].S){
				f=1;
			}
		}
		if(f==0){
			for(int j=pts[i].F+1;j<=pts[i+1].F;j++){
				path.PB({j,pts[i+1].S});
			}
		}
		cout<<path.size()<<" ";
		for(int j=0;j<path.size();j++){
			cout<<path[j].F<<" "<<path[j].S<<" ";
		}
		cout<<"\n";
	}

	return 0;
}