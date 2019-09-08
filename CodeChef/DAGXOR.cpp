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


vector<vector<int> >adj;
int dp[100005][4];
vector<int>leaf;
int Leaf[100005];
void dfs0(int x, int p){
    int f=0;
    for(auto g:adj[x]){
        if(g==p){
            continue;
        }
        else{
            f=1;
            dfs0(g,x);
        }
    }
    if(f==0){
        leaf.PB(x);
    }
}
int dfs(int x, int p, int val){
    if(Leaf[x]==1){
        return dp[x][val];
    }
    if(dp[x][val]!=-1){
        return dp[x][val];
    }
    int ans=0;
    int DP[4];
    for(int i=0;i<4;i++){
        DP[i]=1;
    }
    for(auto g:adj[x]){
        if(g==p){
            continue;
        }
        else{
            for(int i=0;i<=3;i++){
                for(int j=0;j<=3;j++){

                    if((i^j)==val){
                        // Ans=(Ans*(dfs(g,x,j)))%mod;
                        DP[i]=(DP[i]*dfs(g,x,j))%mod;
                    }
                }
                // ans=(ans+Ans)%mod;
            }  
        }
    }
    for(int i=0;i<4;i++){
        ans=(ans+DP[i])%mod;
    }
    return dp[x][val]=ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        leaf.clear();
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<(n-2);i++){
            int u, v;
            cin>>u>>v;
            adj[u].PB(v);
            adj[v].PB(u);
        }

        memset(Leaf,0,sizeof(Leaf));
        // deb(n);
        dfs0(1,0);
        // deb(leaf);
        for(int i=0;i<leaf.size();i++){
            Leaf[leaf[i]]=1;
        }
        int ans=0;
         memset(dp,-1 ,sizeof(dp));
        dp[n][0]=1;
        dp[n][1]=0;
        dp[n][2]=0;
        dp[n][3]=0;
        //fill leaf

        for(int i=0;i<leaf.size();i++){
            int N=leaf[i];
            // deb(N);
            for(int I=0;I<4;I++){
                dp[N][I]=0;
            }

            
            for(int j=0;j<=3;j++){
                for(int k=0;k<=3;k++){
                    dp[N][j^k]+=dp[n][k];
                }
            }
        }
        
        ans=(ans+dfs(1,0,0))%mod;
        ans=(ans*4)%mod;

        ans=ans%mod;
        cout<<ans<<"\n";
        // cout<<0<<"\n";

    }




    return 0;
}