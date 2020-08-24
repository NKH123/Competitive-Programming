#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";

int32_t main(){
    ios::sync_with_stdio(false);
	int t;
	cin>>t;
	vi w;
	while(t--) {
		int n, k;
		cin>>n>>k;
		w.clear();
		w.resize(n);
		int maxi = 0;
		REP(i,0,n){
			cin>>w[i];
			maxi = max(maxi, w[i]);
		}
		if(maxi > k) {
			cout<<-1<<"\n";
			continue;
		}
		int ans = 0;
		int cur = 0;
		// for(int i=0; i<n; i++) {
		// 	if((cur + w[i]) <= k) {
		// 		cur+=w[i];
		// 	}
		// 	else {
		// 		ans++;
		// 		cur=w[i];
		// 	}
		// }
		int i = 0;
		while(i<n) {
			  if((cur + w[i]) <= k) {
			  	cur+=w[i];
			  	i++;
			  }
			  else {
			  	ans++;
			  	cur = 0;
			  }
		}
		ans++;
		cout<<ans<<"\n";

	}    

    return 0;
}