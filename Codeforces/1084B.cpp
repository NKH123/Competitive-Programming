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
#define llp 1000000007
#define trace(x) cout<<#x<<"="<<x<<"\n";

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	ll n,s;
	cin>>n>>s;
	vl a;
	a.resize(n);
	ll mini=1e9;	
	ll sum=0;
	REP(i,0,n){
		cin>>a[i];
		mini=min(a[i],mini);
		sum+=a[i];
	}
	if(sum<s){
		cout<<-1<<"\n";
		return 0;
	}
	long long rem=s;
	
	REP(i,0,n){
		//acq=acq+(a[i]-mini);
		//a[i]-=mini;
		rem=rem-(a[i]-mini);
		a[i]=mini;

		if(rem<=0){
			//acq=acq-rem;
			//trace(rem);
			a[i]=a[i]-(rem);
			rem=0;
			break;
		}
	}
	ll ans=mini;
	//trace(rem);
	//trace(mini);
	if(rem>0){

		ll addint=rem/n;
		ll addrem=rem%n;
		if(addrem>0){
			ans=mini-(addint+1);
		}
		else{
			ans=mini-addint;
		}

	}
	cout<<ans<<"\n";

	/*REP(i,0,n){
		cin>>a[i];
		mini=min(a[i],mini);
	}
	cout<<mini<<"\n";*/



    return 0;
}