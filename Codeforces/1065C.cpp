#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define modn 1000000007
#define all(c) c.begin(), c.end()
#define tr(c, it) for(auto it=(c).begin(); it!=c.end(); it++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bitcount __builtin_popcount
#define ispresent(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define watch(x) cout<< (#x) << " is " << (x) <<"\n";
#define sz(x) ((int)((x).size()))
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;
typedef pair<int, int> pi;
typedef list<int> li;

int n, k;
vll sum;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
    //freopen("a.txt", "r", stdin);
	cin>>n>>k;
	int height[n];
	ll csum[n];
	sum.resize(n);
	rep(i, 0, n) {
		cin>>height[i];
		
	}
	sort(height, height+n);
	rep(i, 0, n) {
		csum[i]=height[i];
		if(i>0 ) {
			csum[i]+=csum[i-1];
			//cout<<csum[i]<<" ";
		}
	}
	
	//cout<<"\n";
	rep(i, 0, n) {
		sum[i]=csum[n-1]-csum[n-i-1]-i*height[n-i-1];
		//cout<<sum[i]<<" ";
	}
	int cnt=0;
	auto it=upper_bound(all(sum), k);
	while(it!=sum.end()) {
		cnt++;
		k+=*(it-1);
		it=upper_bound(it, sum.end(), k);
	}
	cout<<cnt+1<<"\n";
    return 0;
}