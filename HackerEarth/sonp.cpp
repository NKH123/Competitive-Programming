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
int noo=0;


vi adj[100005];
vi vis(100005,0);
vi  siz(100005,0);
void dfs(int v){
    vis[v]=true;
    noo++;
    for(auto g : adj[v]){
        if(!vis[g]){
            dfs(g);
        }
    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    int n,m;
    int k;
    cin>>n>>m>>k;
    // memset(vis,false,sizeof(vis));
    // memset(siz,0,sizeof(siz));
    vis.clear();
    siz.clear();
    vis.resize(n+1);
    siz.resize(n+1);

    REP(i,0,m){
        int A,B;
        cin>>A>>B;
        adj[A].PB(B);
        adj[B].PB(A);

    }
    int noComp=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            noo=0;
            noComp++;
            dfs(i);
            siz[i]=noo;
        }
    }
    // deb(noComp);
    // deb
    // deb(siz);
    if(noComp>k){
        cout<<-1<<"\n";
    }
    else{
        int ans=0;
        REP(i,1,n+1){
            if(siz[i]!=0)
            ans+=(siz[i]-1);
        }
        // deb(ans);
        ans=m-ans;
        // deb(ans);
        ans+=(k-noComp);
        cout<<ans<<"\n";
    }




    return 0;
}