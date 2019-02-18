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

int main()
{   ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vl a(n);
	REP(i,0,n)cin>>a[i];
	sort(a.begin(),a.end());
	int i=0,j=n-1;
	ll ans=0;
	while(i<j){

		ans+=(a[i]+a[j])*(a[i]+a[j]);
		i++;
		j--;
	}
    cout<<ans<<"\n";
    return 0;
}