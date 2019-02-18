#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
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

ll power(ll x, ll y) 
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return (((x*temp)%mod)*temp)%mod; 
}

vl a;
vl b;
vi Expl;
vi adj[100005];
bool vis[100005];
ll x;
ll ccomp=0;
vl AA,BB;
vi aaa;
vi par;
int N=0;
ll dfs1(int v){
    vis[v]=true;
    ll ret=a[v];

    for(auto g:adj[v]){
        if(!vis[g]){
            par[g]=v;
            ll aa=dfs1(g);
            ret=ret^aa;
        }
    }
    b[v]=ret;
    return ret; 
}
vi notan;
void reduce(int v){
    vis[v]=true;
    for(int i=0;i<adj[v].size();i++){
        int g=adj[v][i];

        if(!vis[g] && !Expl[g]){

            if(b[g]!=0 && b[g]!=x){
             Expl[g]=true;
             notan[g]=1;
             a[v]=a[v]^a[g];
             for(auto G:adj[g]){
                if(G!=v && !Expl[G]){
                    adj[v].PB(G);

                }
            }

            adj[g].clear();
            a[g]=-1;
        }
        else{
            reduce(g);
        }
    }
}

}


void solve(int v){
    N++;
    ll vall=a[v];
    vis[v]=true;
    if(a[v]==x){
        AA[v]=1;
        BB[v]=0;
    }
    else if(a[v]==0){
        AA[v]=0;
        BB[v]=1;
    }
    else if(a[v]==-1){
        AA[v]=0;
        BB[v]=0;
    }
    for(auto g:adj[v]){
        if(!vis[g] && !Expl[g]){
            
            solve(g);
        }
        else{
            continue;
        }

        ll xxx=AA[v];
        ll zzz=BB[v];
               //1 0      include                 remove   //1 1            include //0 1
        xxx=(((AA[v]%mod)*(BB[g]%mod))%mod+((AA[v]%mod)*(AA[g]%mod))%mod+((BB[v]%mod)*(AA[g]%mod)))%mod;
               //remove 0 1                include 1 1                   include 0 0
        zzz=(((AA[g])%mod*(BB[v]%mod))+((AA[v]%mod)*(AA[g]%mod))%mod+((BB[v]%mod)*(BB[g]%mod)))%mod;

        AA[v]=xxx;
        BB[v]=zzz;
    }    

}

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    cin>>x;
    memset(vis,0,sizeof(vis));
    a.resize(n+1);
    b.resize(n+1);
    AA.resize(n+1);
    BB.resize(n+1);
    par.resize(n+1);
    Expl.resize(n+1);
    notan.resize(n+1);
    REP(i,1,n+1)cin>>a[i];
    REP(i,0,n-1){
        int A,B;
        cin>>A>>B;
        adj[A].PB(B);
        adj[B].PB(A);
    }
    ll pari=dfs1(1);
    memset(vis,0,sizeof(vis));
    if(pari!=0 && pari!=x){
        cout<<0<<"\n";
        return 0;
    }

    memset(vis,0,sizeof(vis));
    reduce(1);
    
    
    memset(vis,0,sizeof(vis));
    solve(1);
    
    if(x!=0)
    cout<<AA[1]<<"\n";
    else{
       // deb(N);
        if(N==0)N=1;
        cout<<power(2,N-1)<<"\n";
    }

    return 0;
}













