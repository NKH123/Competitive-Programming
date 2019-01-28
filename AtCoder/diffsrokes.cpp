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
	vector<pair<ll,int>>a;
	vector<pair<ll,int>>b;
    //map<int,ll>a;
    //map<int,ll>b;
	REP(i,0,n){
		ll A,B;
		cin>>A>>B;
		a.PB({A,i});
		b.PB({B,i});
    	//a[i]=-1*A;
    	//b[i]=-1*B;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll ans=0;
   // int i=0,j=n-1;
	bool aa[n];
	memset(aa,false,sizeof(aa));
	int ct=0;
   /* for(auto g:a){
    	cout<<g.S<<" ";
    }
    cout<<"\n";*/
	int i,j;
	i=n-1,j=n-1;
	while(ct<n){

		if(ct%2==0){

			while(aa[a[i].S]==true){
				i--;
			}
			ans+=a[i].F;
			aa[i]=true;
		}
		if(ct%2==1){
			while(aa[b[j].S]==true){
				j--;
			}
			ans-=b[j].F;
			aa[j]=true;
		}
		ct++;
	}
	cout<<ans<<"\n";
	return 0;
}