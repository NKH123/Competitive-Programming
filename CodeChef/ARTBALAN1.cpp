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

bool comp(int A,int B){
	return A>B;
}
int main(){
	ios::sync_with_stdio(false);

	int t;
	cin>>t;
	
	vl a(26);
	while(t--){
		a.clear();
		a.resize(26);
		string s;
		set<char>ss;
		ss.clear();
		cin>>s;
		for(auto g:s){
			char aa=g;
			a[aa-'A']++;
			ss.insert(aa);
		}
		ll dis=ss.size();
		int red=0;
		while(!((s.size()%dis)==0)){
			dis--;
			red++;
		}
		
		sort(a.begin(),a.end(),comp);
		
		ll ele=s.size()/dis;
		
		ll ans=0;
		ll ans1=s.size()-a[0];
		for(int i=0;i<dis;i++){
			if(a[i]>ele){
				ans+=a[i]-ele;
			}
		}
		for(int i=dis;i<(dis+red);i++){
			ans+=a[i];
		}
		ans=min(ans,ans1);
		cout<<ans<<"\n";

	}


	return 0;
}