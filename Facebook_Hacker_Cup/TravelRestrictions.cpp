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

int ct = 0;
vector<char> I, O;
vector<int>vis;
vector<vector<int> >adj;
vector<vector<int> >ans;
void dfs(int from, int v){
    vis[v] = ct;
    ans[from][v] = 1;
    for(int g : adj[v]){
        if(ans[from][g] != 1){
            dfs(from, g);
        }
    }

}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T = t;
    while(t--){
        ct = 0;
        int n;
        cin>>n;
        I.clear();
        O.clear();
        I.resize(n);
        O.resize(n);
        ans.clear();
        ans.resize(n,vector<int>(n,-1));
        REP(i,0,n){
            cin>>I[i];
        }
        REP(i,0,n){
            cin>>O[i];
        }
        adj.clear();
        // deb(1);
        adj.resize(n);
        for(int i=0;i<n;i++){
            if(I[i]!='N'){
                if(i!=0){
                    if(O[i-1]!='N'){
                        adj[i-1].PB(i);
                    }
                }
                if(i!=(n-1)){
                    if(O[i+1]!='N'){
                        adj[i+1].PB(i);
                    }
                }

            }
        }
        // deb(2);
        vis.clear();
        vis.resize(n,false);
        for(int i=0;i<n;i++){
            for(auto g:adj[i]){
                dfs(i,g);
            }
        }
        // deb(3);
        // deb(adj); 
        cout<<"Case #"<<(T-t)<<":\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j){
                    cout<<"Y";
                    continue;
                }
                if(ans[i][j] == 1){
                    cout<<"Y";
                }
                else{
                    cout<<"N";
                }
            }
            cout<<"\n";
        }

    }
    return 0;
}