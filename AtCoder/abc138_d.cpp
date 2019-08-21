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

vi adj[210000];
vi val(210000,0);
void dfs(int cur, int par, int Val){
    val[cur]=val[cur]+Val;
    for(auto g:adj[cur]){
        if(g!=par){
            dfs(g,cur,val[cur]);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int n, q;
    cin>>n>>q;    
    REP(i,0,n-1){
        int A, B;
        cin>>A>>B;
        adj[A].PB(B);
        adj[B].PB(A);
    }
    while(q--){
        int A, B;
        cin>>A>>B;
        val[A]=val[A]+B;
    }
    dfs(1,0,val[0]);
    for(int i=1;i<=n;i++){
        cout<<val[i]<<" "; 
    }
    cout<<"\n";
    return 0;
}