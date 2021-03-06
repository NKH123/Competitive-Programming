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
vector<pair<int, int> > adj[100005];
map<int, pair<int, int> >par;
vi occ;
void dfs(int x, int p){
    for(auto g:adj[x]){
        int G=g.F;
        if(G!=p){
            par[G]={x,g.S};
            dfs(G,x);
        }

    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    occ.resize(n+1,0);
    REP(i,0,n-1){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].PB({v,w});
        adj[v].PB({u,w});
    }
    par[1]={0,0};
    dfs(1,0);
    while(q--){
        int u, f;
        cin>>u>>f;
        int cur=u;
        while(cur!=1){
            if(f>=par[cur].S ){
                int ff=0;
                if(occ[par[cur].F]==1){
                    ff=1;
                }
                cur=par[cur].F;
                f-=par[cur].S;
                if(ff==1){
                    break;
                }
            }
            else{
                occ[cur]=1;
                break;
            }
            if(cur==1){
                break;
            }
        }
        cout<<cur<<"\n";
    }



	return 0;
}