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



#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // Your code here
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int> > adj(n);
        for(int i=0; i<n-1; i++) {
            int u, v;
            cin>>u>>v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n);
        vector<int> siz(n);
        function<void(int, int) > dfs = [&](int u, int pr)
        {
            siz[u] = 1;
            vector<int> a;
            for(int v : adj[u]) {
                if(v==pr) continue;
                dfs(v, u);
                siz[u] += siz[v];
                a.push_back(siz[v]);
            }
            a.push_back(n-siz[u]);
            sort(a.begin(), a.end());
            int mx = a.back();
            // if(n-2*mx < 0) {
            //     ans[u] = 0;
            // }
            // else {
            //     if(n&1) {
            //         ans[u] = 0;
            //     }
            //     else {
            //         ans[u] = 1;
            //     }
            // }
            if(mx>(n-mx)){
                ans[u]=0;
            }
            else{
                ans[u]=1;
            }
        };
        dfs(0, -1);
        for(int i=0; i<n; i++) {
            if(n%2==1){
                ans[i]=0;
            }
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}