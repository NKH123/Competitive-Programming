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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
	ll h, w, x, y;
	cin>>h>>w>>x>>y;
	while(__gcd(x,y)!=1){
		ll kk=__gcd(x,y);
		x=x/kk;
		y=y/kk;
	}
	ll k1=min(h/x, w/y);
	ll k2=min(h/y, w/x);
	ll k=max(k1, k2);
	cout<<x*k1<<" "<<y*k1<<"\n";
	
    return 0;
}

