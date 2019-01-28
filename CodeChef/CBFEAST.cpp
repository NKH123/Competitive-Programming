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
void print(deque<pair<int,int> > d){
	for(auto D:d){
		cout<<D.F<<","<<D.S<<" ";
	}
	cout<<"\n";
	cout<<"\n";
}
int main()
{   ios::sync_with_stdio(false);
    freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	int q;
	int k;
	deque<pair<int,int> >d;
	cin>>q>>k;
	int ans=0;
	while(q--){
		int b;
		int di;
		int ci;
		int c;
		cin>>b;
		if(b==1){
			cin>>ci;
			ci=ci^ans;
			cin>>di;
			d.push_front({ci,di});
			print(d);
		}
		else if(b==2){
			cin>>ci;
			ci=ci^ans;
			cin>>di;
			d.push_back({ci,di});
			print(d);
		}
		else if(b==3){
			print(d);
			cin>>c;
			 c=c^ans;
			 trace(c);
			 ans=0;
			int partans=0;
			int f=0;
			for(auto i=d.begin();i<d.end();i++){
				auto it=*i;
				if(it.F<=(c+k) && it.F>=(c-k)){
					partans+=it.S;
					ans=max(ans,partans);
				}
				else{
					partans=0;
				}
			}
			/*for(auto D:d){
				if(D.F<=(c+k) && D.F>=(c-k)){
					partans+=D.S;
					f=1;
					trace(partans);
				}
				else if(f==1){
					f=0;
					ans=max(partans,ans);
					partans=0;
				}
			}
			if(partans!=0){
				ans=max(partans,ans);
					partans=0;
			}*/
			//cout<<ans<<"\n";
			trace(ans);
		}
	}

    return 0;
}