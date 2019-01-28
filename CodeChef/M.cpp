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
	while(1){
		int a;
		cin>>a;
		int max=-1;
		int ans;
		vi A;
		for(int i=1;i<=a;i++){
			cout<<a<<" % "<<i<<" = "<<(a%i)<<"\n";
			if((a%i)>max){
				max=(a%i);
				ans=i;

			}
		}
		for(int i=1;i<=a;i++){
			if((a%i)==max){
				A.PB(i);
			}
		}
		cout<<"Answer is "<<ans<<"\n";
		cout<<"i.e "<<a<<" % "<<ans<<" = "<<max<<"\n";
		cout<<"There are "<<A.size()<<" values.\n";
		for(auto g:A){
			cout<<g<<" ";
		}
		cout<<"\n";
	}

	return 0;
}