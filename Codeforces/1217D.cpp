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

vector<int>adj[5500];
vector<int>order;
int vis[5500];
int active[5500];
int f=0;
vector<int>color;
map<pair<int, int>, int> EdgetoInd;
map<int,int>IndtoColor;
void dfs0(int x, int par){
    vis[x]=1;
    for(auto g:adj[x]){
        if(vis[g]==0){
            dfs0(g,x);
        }
    }
    order.PB(x);
}
void dfs1(int x, int par){
    vis[x]=1;
    active[x]=1;
    for(auto g:adj[x]){
        if(vis[g]==0){
            int ind=EdgetoInd[{x,g}];
            color[ind]=1;
            dfs1(g,x);
        }
        else{
            if(active[g]==1){
                f=1;
                int ind=EdgetoInd[{x,g}];
                color[ind]=2;
            }
            else{
                int ind=EdgetoInd[{x,g}];
                color[ind]=1;
            }
        }
    }
    active[x]=0;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;  
    color.clear();
    color.resize(m);    
    for(int i=0;i<m;i++){
        int A, B;
        cin>>A>>B;
        adj[A].PB(B);
        EdgetoInd[{A,B}]=i;
    }
    memset(vis,0,sizeof(vis));
    // for(int i=1;i<=n;i++){
    //     if(vis[i]==0)
    //     dfs0(i,0);
    // }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs1(i,0);
        }
    }

    if(f==0){
        cout<<1<<"\n";
        for(int i=0;i<m;i++){
            cout<<1<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<2<<"\n";
        for(int i=0;i<m;i++){
            cout<<color[i]<<" ";
        }
        cout<<"\n";
    }





    return 0;
}