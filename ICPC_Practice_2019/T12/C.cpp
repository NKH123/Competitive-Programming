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

vector<pair<int,int> >edges;
vector<pair<int,int> >Removed;
vector<pair<int,int> >Added;
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    DSU D(n+1);
    for(int i=0;i<(n-1);i++){
        int A, B;
        cin>>A>>B;
        edges.PB({A,B});
    }
    for(int i=0;i<(n-1);i++){
        int A=edges[i].F;
        int B=edges[i].S;
        if(D.same(A,B)){
            Removed.PB({A,B});
        }
        else{
            D.unite(A,B);
        }
    }
    int root=D.find(1);
    for(int i=1;i<=n;i++){
        if(D.same(i,root)){

        }
        else{
            Added.PB({i,root});
            D.unite(i,root);
        }
    }
    cout<<Added.size()<<"\n";
    for(int i=0;i<Added.size();i++){
        cout<<Removed[i].F<<" "<<Removed[i].S<<" "<<Added[i].F<<" "<<Added[i].S<<"\n";
    }



    return 0;
}