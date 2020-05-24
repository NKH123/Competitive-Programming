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
#define endl "\n"
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


vector<int>adj[1005];
int vis[1005];
int col[1005];
int f=1;
void dfs(int X){
    vis[X]=1;

    for(auto g:adj[X]){
        if(vis[g]==1){
            if(col[g]==col[X]){
                f=0;
            }
        }   
        else{
            col[g]=1^col[X];
            dfs(g);
        }
    }
}
// void check()
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    // vector<vector<pair<int, int> > >v;
    vector<pair<pair<int, int> , int> >vv;
    while(t--){
        int n;
        cin>>n;
        f=1;
        // v.clear();
        vv.clear();
        for(int i=0;i<n;i++){
            int A, B, C;
            cin>>A>>B>>C;
            vv.PB({{A,B},C});
        }
        for(int i=0;i<1005;i++){
            adj[i].clear();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                else{
                    if(vv[i].S!=vv[j].S){
                        continue;
                    }
                    else{
                        //check for overlap
                        // if(vv[i].F.F<=)
                        int L1=vv[i].F.F;
                        int R1=vv[i].F.S;
                        int L2=vv[j].F.F;
                        int R2=vv[j].F.S;
                        if((L1<=R2 && L1>=L2) || (R1<=R2 && R1>=L2) || (L2<=R1 && L2>=L1) || (R2<=R1 && R2>=L1)){
                            adj[i].PB(j);
                            adj[j].PB(i);
                        }
                    }
                }
            }
        }
        memset(col,-1,sizeof(col));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                col[i]=0;
                dfs(i);
            }
        }
        // f=1;
        // memset(vis,0,sizeof(vis));
        if(f==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }

return 0;
}