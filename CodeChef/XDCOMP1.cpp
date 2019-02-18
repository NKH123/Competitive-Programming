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
vl a;
vi adj[100005];
bool vis[100005];
ll x;
ll ccomp=0;
vl AA,BB;
 vi aaa;
/*ll dfs(int v){
    vis[v]=true;
    ll ret=a[v];
    for(auto g:adj[v]){
        if(!vis[g]){
            ll aa=dfs(g);
            if(aa==x){
                ccomp++;
            }
            else{
                ret=ret^aa;
            }
        }
    }
    return ret;

}*/
ll dfs1(int v){
    vis[v]=true;
    ll ret=a[v];
    for(auto g:adj[v]){
        if(!vis[g]){
            ll aa=dfs1(g);
            ret=ret^aa;
        }
    }
    return ret; 
}

void reduce(int v){
    //deb(v);
    //trace(v);
    //trace(a[v]);
    vis[v]=true;
    int f=0;
    if(a[v]!=0 && a[v]!=x){
        f=1;
    }
    if(f==1){
        //deb("i'm here");
        //trace("i'm here\n");
        ll valas=0;

        aaa.clear();
        int par;
        int ispar=0;
        for(auto g:adj[v]){ 
            /*if(vis[g]){
               
                ispar=1;
                par=g;
            }*/
            vis[g]=true;
            valas=valas^a[g];
            aaa.PB(g);

        }
        a[v]=valas^a[v];
        adj[v].clear();
        for(auto g:aaa){
            for(auto vv:adj[g]){
                if(vv!=v)
                    adj[v].PB(vv);
            }
        }
       /* if(ispar){
            adj[par].clear();
            for(auto g:adj[v]){
                adj[par].PB(g);
            }
        }*/
        reduce(v);
    }
    else{
        for(auto g:adj[v]){
            if(!vis[g]){
                reduce(g);
            }
        }
    }
}

/*void reduce(int v){
    queue<int>q=queue<int>();
    q.push(v);
    //vis[v]=true;
    while(!q.empty()){
        int V=q.front();
        vis[V]=true;
        q.pop();
        int f=0;
        if(a[V]!=0 && a[V]!=x){
            f=1;
        }
        while(f){
            aaa.clear();
            for(auto g:adj[V]){
                if(vis[g])continue;
                a[V]=a[V]^a[g];
                for(auto G:adj[g]){
                    if(G!=g)
                        aaa.PB(G);
                }
            }
            adj[V].clear();
            for(auto g:aaa){
                adj[V].PB(g);
            }
            if(a[V]!=0 && a[V]!=x){
                f=1;
            }
            else{
                f=0;
            }
        }

        for(auto g:adj[V]){
            if(!vis[g]){
                q.push(g);
            }
        }

        
    }
}*/

void solve(int v){
    ll vall=a[v];
    vis[v]=true;
    if(a[v]==x){
        AA[v]=1;
        BB[v]=0;
    }
    else{
        AA[v]=0;
        BB[v]=1;
    }
    for(auto g:adj[v]){
        if(!vis[g]){
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
    //deb(x);
    memset(vis,0,sizeof(vis));
    a.resize(n+1);
    AA.resize(n+1);
    BB.resize(n+1);
    REP(i,1,n+1)cin>>a[i];
   // deb(a);
    REP(i,0,n-1){
        int A,B;
        cin>>A>>B;
        adj[A].PB(B);
        adj[B].PB(A);
    }
    //deb("input done");
    //intitial condition
    ll pari=dfs1(1);
    //deb("pari found");
   // deb(pari);
    memset(vis,0,sizeof(vis));
    //dfs(1);
    if(pari!=0 && pari!=x){
        cout<<0<<"\n";
        return 0;
    }
    else if(pari==x){
        memset(vis,0,sizeof(vis));
        reduce(1);
       // deb("reduce done");
        memset(vis,0,sizeof(vis));
        solve(1);
       // deb("solve done");


    }
    else if(pari==0){
        memset(vis,0,sizeof(vis));
        reduce(1);
       // deb("reduce done");
        memset(vis,0,sizeof(vis));
        solve(1);
     //   deb("solve done");


    }
   // deb("final");
    cout<<AA[1]<<"\n";
    return 0;
}