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
vi adj[200005];
vector<pair<int, int > >edg;

vector<pair<int, int > >edg1;
vi adj1[200005];
int deg[200005];
bool vis[200005];
int maxdeg=-1;
int degnod=-1;
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
        par[a] = b;
        parts[b].splice(parts[b].end(), parts[a]);
    }
};
void dfs(int x){
    vis[x]=true;
    for(auto g:adj[x]){
        deg[x]++;
        if(!vis[g]){
            dfs(g);
        }
    }
    if(deg[x]>maxdeg){
        maxdeg=deg[x];
        degnod=x;
    }
}


int32_t main(){
	ios::sync_with_stdio(false);
    memset(deg,0,sizeof(deg));
    memset(vis,false,sizeof(vis));
    int n, m;
    cin>>n>>m;
    REP(i,0,m){
        int A, B;
        cin>>A>>B;
        adj[A].PB(B);
        adj[B].PB(A);
        edg.PB({A,B});
    }
    dfs(1);
    DSU D(n+1);
    for(auto g:adj[degnod]){
        D.unite(degnod,g);
        edg1.PB({degnod,g});

    }
    for(auto g:edg){
        if(g.F==degnod || g.S==degnod)continue;
        if(D.same(g.F,g.S))continue;
        edg1.PB(g);
        D.unite(g.F,g.S);
    }
    // cout<<edg1.
    for(auto g:edg1){
        cout<<g.F<<" "<<g.S<<"\n";
    }

	return 0;
}