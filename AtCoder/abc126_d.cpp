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

vector<pair<int, int > >adj[100005];
vector<int>col;
int dis[100005];
void dfs(int x, int p){
    for(auto g:adj[x]){
        if(g.F!=p){
            dis[g.F]=dis[x]+g.S;
            if(dis[g.F]%2==0){
                col[g.F]=0;
            }
            else{
                col[g.F]=1;
            }
            dfs(g.F,x);
        }
    }
}


int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    memset(dis,0,sizeof(dis));
    col.resize(n+1);
    REP(i,0,n-1){
        int A, B, C;
        cin>>A>>B>>C;
        adj[A].push_back({B,C});
        adj[B].push_back({A,C});
    }
    col[1]=0;
    dfs(1,0);
    REP(i,1,n+1){
        cout<<col[i]<<"\n";
    }



	return 0;
}