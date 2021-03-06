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
#define llp 1000000007
#define mod 1000000007

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
struct DSU {
    vector<ll> par;
    vector<ll> sz;
    vector<list<ll>> parts;
    DSU(int n) {
        REP(i, 0, n) {
            par.PB(i);
            sz.PB(1);
            parts.PB({i});
        }
    }

    ll find(ll a) {
        return par[a] = par[a] == a ? a : find(par[a]);
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    void unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b);
        // sz[a] <= sz[b]
        sz[b] += sz[a];
        sz[a]+=sz[b];
        par[a] = b;
        parts[b].splice(parts[b].end(), parts[a]);
    }
};

int vis[100005];
int32_t main(){
	ios::sync_with_stdio(false);
    int n, m;
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    DSU d(n+1);
    REP(i,0,m){
        int X, Y, Z;
        cin>>X>>Y>>Z;
        if(!d.same(X,Y)){
            d.unite(X,Y);
        }
    }
    int ans=0;

    for(int i=1;i<=n;i++){
        // deb(i);
        int A=d.find(i);
        // deb(A);
        if(vis[A]==0){
            ans+=1;
            // deb("yes");
            // deb(d.sz[A]);
            vis[A]=1;
        }
    }

    cout<<ans<<"\n";

	return 0;
}