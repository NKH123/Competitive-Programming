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

int a[1005][29];
int main(){
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--){
		//trace(t);
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		REP(i,0,n){
			string s;
			cin>>s;
			for(auto g:s){
				//trace(g);
				char aa=g;
				//trace(aa);
				//trace(aa-'a');
				if(!a[i][aa-'a'])
				a[i][aa-'a']++;
			}
		}
		ll ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<26;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		for(int i=0;i<26;i++){
		//	trace(i);
			ll ANS=a[0][i];
			for(int j=1;j<n;j++){
		//		trace(j);
		//		trace(ANS);
		//		trace(a[j][i]);
				ANS=ANS&a[j][i];
			}
			trace(i);
			trace(ANS);
			if(ANS!=0)ans++;
			//trace(i);
			//trace(ans);
		//	trace(ans);
		}
		cout<<ans<<"\n";
	}
	




	return 0;
}