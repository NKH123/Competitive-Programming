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
#define mod 1000000007
#define endl "\n"
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

vector<int> Centroid(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[v] > n / 2) is_centroid = false;
        }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<vector<int> > g;
    while(t--) {
        g.clear();
        int n;
        cin>>n;
        g.resize(n);
        int arb1, arb2;
        for(int i=0; i<(n-1); i++) {
            int A, B;
            cin>>A>>B;
            arb1=A;
            arb2=B;
            A--;
            B--;
            g[A].PB(B);
            g[B].PB(A);
        }
        auto centroids = Centroid(g);
        if (centroids.size() == 1) {
            int c = centroids[0];
            cout<<arb1<<" "<<arb2<<"\n";
            cout<<arb1<<" "<<arb2<<"\n";
        //
        } else if (centroids.size() == 2) {
            int c1 = centroids[0];
            int c2 = centroids[1];
            int X=-1;
            for(auto G: g[c1]) {
                if (G!=c2) {
                    X=G;
                }
            }
            cout<<(c1+1)<<" "<<(X+1)<<"\n";
            cout<<(c2+1)<<" "<<(X+1)<<"\n";
        //
        }
    }

    return 0;
}