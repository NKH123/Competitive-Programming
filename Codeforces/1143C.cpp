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
vector<set<int>>adj;
vi c;
vi P;
set<int>Rem;
void dfs(int x, int p){
    // deb(x);
    int f=0;
    if(c[x]==1){
        f=1;
    }
    int ff=1;
    for(auto g:adj[x]){
        if(g!=p){
            P[g]=x;
            dfs(g,x);
            if(c[g]==0){
                ff=0;
            }
        }
    }
    if(f==1 && ff==1){
        Rem.insert(x);
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    adj.resize(n+1);
    c.resize(n+1);
    int root;
    P.resize(n+1);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a>>c[i];
        if(a==-1){
            root=i;
        }
        if(a!=-1)
            adj[a].insert(i);
        adj[i].insert(a);
    }
    P[root]=-1;
    // deb("here");
    dfs(root,-1);
    // deb("here");
    if(Rem.size()==0){
        cout<<-1<<"\n";
        return 0;
    }
    while(Rem.size()!=0){
        int v=*Rem.begin();
        Rem.erase(Rem.begin());
        cout<<v<<" ";
        // int par=P[v];

        // for(auto g:adj[v]){
        //     if(g!=par){
        //         P[g]=par;
        //     }
        // }
        // adj[par].erase(adj[par].find(v));
        // for(auto g:adj[v]){
        //     if(g!=par){                
        //         adj[par].insert(g);
        //     }
        // }
        // if(c[par]==1){
        //     int f=1;
        //     for(auto g:adj[par]){
        //         if(g!=P[par]){
        //             if(c[g]==0){
        //                 f=0;
        //             }
        //         }
        //     }
        //     if(f==1){
        //         Rem.insert(par);
        //     }
        // }
    }
    cout<<"\n";




    return 0;
}