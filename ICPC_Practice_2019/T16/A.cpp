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

int n, m;
// vector<int>adj[100005];
vector<pair< int, int  > >adj[100005]; 
vector<int>vis;
map<pair<int, int> , int>NoEdge;
int ans=-1;
vector<int>ind;
void dfs(int x, int minTillNow, int Ind){

    // deb(x);
    // cerr<<"Visiting "<<x<<"\n";
    vis[x]=1;
    for(auto g:adj[x]){
        if(vis[g.F]==2){
            continue;
        }
        else if(vis[g.F]==1){
            // deb("**");
            //     deb(x);
            //     deb(g.F);
            //     deb(minTillNow);
            // deb("**");
            // ind.PB(Ind);
            // ans=max(ans,minTillNow);

            if(g.S<minTillNow){
                int newInd=NoEdge[{x,g.F}];
                // dfs(g.F,g.S,newInd);
                ind.PB(newInd);
                ans=max(ans,g.S);
            }
            else{
                // dfs(g.F,minTillNow,Ind);
                ind.PB(Ind);
                ans=max(ans,minTillNow);
            }
        }
        else{
            if(g.S<minTillNow){
                int newInd=NoEdge[{x,g.F}];
                dfs(g.F,g.S,newInd);
            }
            else{
                dfs(g.F,minTillNow,Ind);
            }
        }
    }
    vis[x]=2;
}




int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    // adj.clear();
    ind.clear();
    // adj.resize(n+1);
    vis.clear();
    vis.resize(n+1);
    for(int i=0;i<m;i++){
        int A, B, C;
        cin>>A>>B>>C;
        adj[A].PB({B,C});
        NoEdge[{A,B}]=i+1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,1e18, -1);
        }
    }
    cout<<ans<<" "<<ind.size()<<"\n";
    for(int i=0;i<ind.size();i++){
        cout<<ind[i]<<" ";
    }
    cout<<"\n";


    return 0;
}