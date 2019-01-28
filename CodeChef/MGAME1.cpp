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

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	ll n,p;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>p;
		if(n==1 || n==2){
			cout<<p*p*p<<"\n";
		}
		/*else if(n==2){
			if()
		}*/
		else{
			ll ans=0;
			ll i=(n/2)+1;
			ans+=(p-((n%i)+1)+1)*(p-((n%i)+1)+1)+(p-(n+1)+1)*((p-((n%i)+1)+1))+(p-(n+1)+1)*(p-(n+1)+1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}