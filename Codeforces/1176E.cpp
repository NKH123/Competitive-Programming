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
vector<vector<int>>adj;
vector<bool>vis;
vector<bool>col;
vi ans;
void dfs(int x){
    int f=0;
    vis[x]=true;
    for(auto g:adj[x]){
        if(col[g]==true){
            f=1;
        }
    }
    if(f==0){
        col[x]=true;
        ans.PB(x);

    }
    for(auto g:adj[x]){
        if(!vis[g]){
            dfs(g);
        }
    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        adj.clear();
        int m;
        cin>>n>>m;
        adj.resize(n+1);
        vis.clear();
        vis.resize(n+1,false);
        col.clear();
        col.resize(n+1,false);
        ans.clear();
        for(int i=0;i<m;i++){
            int A, B;
            cin>>A>>B;
            adj[A].PB(B);
            adj[B].PB(A);
        }
        dfs(1);
        if(ans.size()<=(n/2)){
            cout<<ans.size()<<"\n";

            REP(i,0,ans.size()){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            int k=n-ans.size();
            cout<<k<<"\n";
            for(int i=1;i<=n;i++){
                if(!col[i]){
                    cout<<i<<" ";
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}