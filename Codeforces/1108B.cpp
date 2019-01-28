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
	int n;
	cin>>n;
	vi a;
	a.resize(n);
	REP(i,0,n)cin>>a[i];
	sort(a.begin(),a.end());
    //print(a);
	int x=a[n-1];
	int y;
	int f=0;
	for(int i=0;i<(n);i++){
		if(x%a[i]!=0){
			f=1;
			break;
		}
	}
	if(f==0){
		int ct=0;
		for(int i=0;i<(n);i++){
			if(a[i]==x){
				ct++;
			}
		}
		if(ct>1){
			y=x;
		}
		else{
			y=a[n-2];
		}

	}
	else{
		for(int i=0;i<(n);i++){
			if(x%a[i]!=0){
				y=a[i];

			}
		}
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}