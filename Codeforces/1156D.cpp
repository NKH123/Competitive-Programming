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

vector<pair<int, int> >adj[200005];
int dp[200005][3];
bool vis[200005];
void dfs(int x, int p){
    deb(x);
    vis[x]=true;
    for(auto g:adj[x]){
        int G=g.F;
        if(!vis[G]){
            dfs(G, x);
            if(g.S==1){
                dp[x][1]+=1;
                dp[x][1]+=dp[G][0];
            }
            else{
                dp[x][0]+=1;
                dp[x][0]+=dp[G][0];
                dp[x][1]+=dp[G][1];
            }
        }
    }
   for(int i=0;i<adj[x].size();i++){
        for(int j=i+1;j<adj[x].size();j++){
            auto g=adj[x][i];
            auto h=adj[x][j];
            if(g==h || g.F==p || h.F==p)continue;
            if(g.S==0 && h.S==0){
                dp[x][2]+=1;
                dp[x][2]+=(dp[g.F][0]*dp[h.F][0])+(dp[g.F][1]*dp[h.F][0])+(dp[g.F][0]*dp[h.F][1]);
            }
            else if(g.S==0 && h.S==1){
                dp[x][2]+=1;
                dp[x][2]+=(dp[g.F][0]*dp[h.F][0]);
            }
            else if(g.S==1 && h.S==0){
                dp[x][2]+=1;
                dp[x][2]+=(dp[g.F][0]*dp[h.F][0]);
            }
            else if(g.S==1 && h.S==1){
                
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
    int n;
    cin>>n;
    REP(i,0,n-1){
        int A,B,C;
        cin>>A>>B>>C;
        adj[A].PB({B,C});
        adj[B].PB({A,C});
    }
    deb("dfs start");
    dfs(1,0);
    deb("dfs end");
    int sum=0;
    for(int i=1;i<=n;i++){
        cout<<i<<"="<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";
    }
    for(int i=1;i<=n;i++){
        sum+=2*dp[i][0]+2*dp[i][1]+2*dp[i][2];
    }
    cout<<sum<<"\n";

	return 0;
}