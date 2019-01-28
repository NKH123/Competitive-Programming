#include<bits/stdc++.h>
using namespace std;


// type definitions
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef complex<int> ci;
typedef complex<double> cd;
typedef complex<long double> cld;

// macros
#define rep(i, a, b) for(int i=a; i<b; i++)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define all(c) c.begin(), c.end()
#define tr(c, it) for(auto it=(c).begin(); it!=c.end(); it++)
#define pb push_back
#define mp make_pair
#define bitcount __builtin_popcount
#define ispresent(c, x) ((c).find(x) != (c).end())
#define watch(x) cout<< (#x) << " is " << (x) <<"\n";
#define sz(x) ((int)((x).size()))
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
#define pii2ll(p) ((ll)(p).first<<32 | (p).second)

// template functions
template <typename T>
inline void printV(vector<T>& a) { rep(i, 0, sz(a)) { cout<<a[i]<<" "; } cout<<"\n"; }
template <typename T>
inline void print(T a) { cout<<a<<"\n"; }
template <typename T>
inline void print(T a, T b) { cout<<a<<" "<<b<<"\n"; }
template <typename T>
inline void print(T a, T b, T c) { cout<<a<<" "<<b<<" "<<c<<"\n"; }
template <typename T>
inline void print(T a, T b, T c, T d) { cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"; }
template <typename T>
inline void printpii(pair<T, T> p) { cout<<p.first<<" "<<p.second<<"\n"; }
template <typename T>
inline void printVV(vector<vector<T>>& a)
{
	rep(i, 0, sz(a)) {
		printV(a[i]);
	}
	cout<<"\n";
}

template <typename T>
inline void clearVV(vector<vector<T>>& a)
{
	for(auto& x:a) {
		x.clear();
	}
	a.clear();
}

template <typename T>
inline void readV(vector<T>& a) { rep(i, 0, sz(a)) cin>>a[i]; }
template <typename T>
inline void read(T& a) { cin>>a; }
template <typename T>
inline void read(T& a, T& b) { cin>>a>>b; }
template <typename T>
inline void read(T& a, T& b, T& c) { cin>>a>>b>>c; }
template <typename T>
inline void read(T& a, T& b, T& c, T& d) { cin>>a>>b>>c>>d; }
template <typename T>
inline void readpii(pair<T, T>& p) { cin>>p.first>>p.second; }
template <typename T>
inline void readVV(vector<vector<T>>& a)
{
	rep(i, 0, sz(a)) {
		readV(a[i]);
	}
}


// constants
const long double eps = 1e-9;
const int inf = 5e8;
const int modn = 1e9+7;
const int MAX = 1e5;

vector<vector<pair<int, int>>> adj;
vector<ll> cost;
vector<bool> marked;

void dfs(int u, int pr)
{
	for(auto p:adj[u]) {
		int v=p.first;
		int w=p.second;
		if(v!=pr) {
			dfs(v, u);
			cost[u]=max(cost[u], w+cost[v]);
		}
	}
}

bool dfs2(int u, int v, ll &w)
{
	marked[u]=1;
	for(auto p:adj[u]) {
		int nx=p.first;
		int we=p.second;
		if(nx==v) {
			w=we;
			return 1;
		}
		if(!marked[nx]) {
			ll tmp=0;
			if(dfs2(nx, v, tmp)) {
				w=tmp+we;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
	int t;
	cin>>t;
	while(t--) {
		int n, q;
		cin>>n>>q;
		clearVV(adj);
		cost.clear();
		marked.clear();
		
		cost.resize(n+1);
		adj.resize(n+1);
		marked.resize(n+1);
		for(int i=0; i<n-1; i++) {
			int u, v, w;
			cin>>u>>v>>w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		dfs(1, -1);
		
		while(q--) {
			int u, v;
			ll x;
			cin>>u>>v>>x;
			ll weight=0;
			marked.clear();
			marked.resize(n+1);
			dfs2(u, v, weight);
			//~ watch(weight);
			
			ll ans=max(weight, cost[u]+cost[v]+x);
			cout<<ans<<"\n"; 
		}
	}
    return 0;
}

