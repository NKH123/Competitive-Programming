#include<bits/stdc++.h>
using namespace std;

//macros
#define modn 1000000007
#define watch(x) cout<<(#x)<<" is "<<x<<"\n";
#define all(c) c.begin(), c.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(c) ((int)(c).size())

//type definitions
typedef long long ll;

//template functions
template<typename T>
void printV(vector<T> &a)
{
	for(int i=0; i<sz(a); i++) {
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//constants
const int MAX = 1e5;
const int inf = 5e8;
const double pi = acos(-1);

void printVV(vector<vector<int>> &a)
{
	int n=a.size();
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

inline int add(int a, int b)
{
	int ret=((ll)a+b)%modn;
	if(ret<0) {
		ret=(ret+modn)%modn;
	}
	return ret;
}

inline int mul(int a, int b)
{
	int ret=((ll)a*b)%modn;
	return ret;
}

vector<vector<int>> matmul(vector<vector<int>> &a, vector<vector<int>> &b)
{
	int n=a.size();
	vector<vector<int>> c(n, vector<int>(n));

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				c[i][j]=add(c[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return c;
}

vector<vector<int>> power(vector<vector<int>> a, ll k)
{
	int n=a.size();
	vector<vector<int>> res(n, vector<int>(n));
	for(int i=0; i<n; i++) res[i][i]=1;

	while(k>0) {
		if(k&1) {
			res=matmul(res, a);
		}
		a=matmul(a, a);
		k>>=1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//Your code here
	ll n, q, k, m;
	cin>>n>>q>>k>>m;
	vector<vector<int>> adj(n, vector<int>(n));
	for(int i=0; i<m; i++) {
		int u, v;
		cin>>u>>v;
		u--, v--;
		adj[u][v]=1;
	}

	//~ printVV(adj);

	adj=power(adj, k);

	//~ printVV(adj);

	while(q--) {
		int u, v;
		cin>>u>>v;
		u--, v--;
		assert(u>=0 and u<n and v>=0 and v<n);
		cout<<adj[u][v]<<"\n";
	}
	return 0;
}
