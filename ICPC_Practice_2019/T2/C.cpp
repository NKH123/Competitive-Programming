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
int f=0;

vector<int>adj[301000];
int vis[301000];
vector<int>deg;
vector<int>tops;
vector<vector<int> >par;
void dfs(int x){
    vis[x]=2;
    for(auto g:adj[x]){
        if(vis[g]==2){
            f=1;
            continue;
        }
        else if(vis[g]==0){
            deg[g]++;
            dfs(g);
        }
        else{
            deg[g]++;
        }       
    }
    tops.PB(x);
    vis[x]=1;
}
void dfs1(int x){
    vis[x]=1;
    for(auto g:adj[x]){
        par[g].PB(x);
        if(vis[g]==0){
            dfs1(g);
        }
    }

}
vector<vector<int> >M;

int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    int m;
    cin>>n>>m;
    string s;
    cin>>s;
    deg.resize(n+1,0);
    M.resize(n+1,vector<int>(26));
    for(int i=0;i<m;i++){
        int A, B;
        cin>>A>>B;
        adj[A].PB(B);
    }
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    if(f==1){
        cout<<-1<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        M[i][s[i-1]-'a']++;
    }
    par.resize(n+1);
    memset(vis,0,sizeof(vis));
    queue<int>Q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            Q.push(i);
        }
    }
    while(Q.size()!=0){
        int x=Q.front();
        vis[x]=1;
        Q.pop();
        for(int i=0;i<26;i++){
            ans=max(ans,M[x][i]);
        }
        for(auto g:adj[x]){
            if(vis[g]==0){
                for(int i=0;i<26;i++){
                    char C='a'+i;
                    M[g][i]=max(M[g][i],M[x][i]+(s[g-1]==(C)?1:0));
                }
                deg[g]--;
                if(deg[g]==0){
                    Q.push(g);
                }
            }
        }
    }
    cout<<ans<<"\n";



    return 0;
}