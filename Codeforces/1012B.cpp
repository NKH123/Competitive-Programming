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
#define sz(x) (int)(x.size())
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
        par[a] = b;
        parts[b].splice(parts[b].end(), parts[a]);
    }
};

int n, m, q;
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    DSU d(n+m);
    while(q--){
        int i; int j;cin>>i>>j;
        i--;
        j--;
        j=j+n;
        d.unite(i,j);


    }
    int co=0;
    vector<bool>vis(n+m,false);
    for(int i=0;i<n+m;i++){
        int par=d.find(i);
        if(!vis[par]){
            co++;
            vis[par]=true;
        }
    }
    cout<<co-1<<"\n";
    return 0;
}