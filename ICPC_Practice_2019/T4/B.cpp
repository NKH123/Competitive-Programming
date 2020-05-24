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
vector<int>vis;
set<pair<int,int> >PP;
vi a;
int root=0;
int mini=0;
void dfs(int x, int p){
    vis[x]=1;
    for(auto g:adj[x]){
        if(g==p){
            continue;
        }
        if(PP.find({min(x,g),max(x,g)})==PP.end())
            if(vis[g]==1){
                PP.insert({min(x,g),max(x,g)});
            // deb("cufd");
                mini++; 
                if(a[x]==g){
                    a[x]=root;
                }
                else{
                    a[g]=root;
                }
            }
            else{
                dfs(g,x);
            }
        }
    }
    struct DSU {
        vector<ll> par;
        vector<ll> sz;
        vector<list<ll>> parts;
        DSU(int n) {
            REP(i, 0, n) {
                par.PB(i);
                sz.PB(1);
                parts.PB({i});
            }
        }

        ll find(ll a) {
            return par[a] = par[a] == a ? a : find(par[a]);
        }

        bool same(ll a, ll b) {
            return find(a) == find(b);
        }

        void unite(ll a, ll b) {
            a = find(a);
            b = find(b);
            if(a == b) return;
            if(sz[a] > sz[b]) swap(a, b);
        // sz[a] <= sz[b]
            sz[b] += sz[a];
            par[a] = b;
            parts[b].splice(parts[b].end(), parts[a]);
        }
    };

    int32_t main(){
        ios::sync_with_stdio(false);
        int n;
        cin>>n;
        a.resize(n+1);
        DSU D(n+1);
        int Noroots=0;
        int ff=0;
        REP(i,1,n+1){
            cin>>a[i];
            if(a[i]==i){
                if(ff==0){
                    root=i;
                    ff=1;
                }
                Noroots++;
            }
        }
        set<int>S;
        for(int i=1;i<=n;i++){
            if(D.same(i,a[i])){
                if(i==a[i]){
                    S.insert(i);
                }
                a[i]=-1;

            }
            else{
                D.unite(i,a[i]);
            }
        }
        int f=0;
        // deb(a);
        for(int i=1;i<=n;i++){
            if(a[i]==-1){
                if(S.find(i)!=S.end()){
                    root=i;
                    a[i]=i;
                    f=1;
                    break;
                }
                else{

                }
            }
        }
        if(f==0){
            for(int i=1;i<=n;i++){
                if(a[i]==-1){
                    a[i]=i;
                    root=i;
                    mini++;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]==-1){
                a[i]=root;
                mini++;
            }
        }
        


    // if(Norrots)

//     if(Noroots>1){
//         for(int i=1;i<=n;i++){
//             if(i==root){
//                 continue;
//             }
//             else{
//                 if(a[i]==i){
//                     mini++;
//                     // deb(i);
//                     a[i]=root;
//                 }
//             }
//         }
//     }
//     if(root==0){
//         mini++;
//         a[1]=1;
//     root=1;
// }
//     vis.resize(n+1,0);
//     adj.resize(n+1);
//     for(int i=1;i<=n;i++){
//         int A=i;
//         int B=a[i];
//         if(A!=B){
//             adj[A].PB(B);
//             adj[B].PB(A);
//         }
//     }

//     dfs(root,0);
//     for(int i=1;i<=n;i++){
//         if(vis[i]==0){
//             // deb(i);
//             dfs(i,0);
//         }
//     }
    cout<<mini<<"\n";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";






        return 0;
    }