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

vector<int>adj[2][200005];
bool vis1[200005];
bool vis2[200005];
map<pair<int, int>, int>M;
vi a(2000005),b(2000005);
int no=0;
void dfs1(int x){
    vis1[x]=true;
    a[x]=no;
    for(auto g:adj[0][x]){
        if(vis1[g]==false){
            dfs1(g);
        }
    }
}
void dfs2(int x){
    vis2[x]=true;
    b[x]=no;
    for(auto g:adj[1][x]){
        if(vis2[g]==false){
            dfs2(g);
        }
    }
}


int32_t main(){
	ios::sync_with_stdio(false);
    int n, k, l;
    memset(vis1,false,sizeof(vis1));
    memset(vis2,false,sizeof(vis2));
    cin>>n>>k>>l;
    REP(i,0,k){
        int A, B;
        cin>>A>>B;
        adj[0][A].PB(B);
        adj[0][B].PB(A);
    }
    REP(i,0,l){
        int A, B;
        cin>>A>>B;
        adj[1][A].PB(B);
        adj[1][B].PB(A);
    }    
    for(int i=1;i<=n;i++){

        if(vis1[i]==false){
            no++;
            dfs1(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(vis2[i]==false){
            no++;
            dfs2(i);
        }
    }
    for(int i=1;i<=n;i++){
        M[{a[i],b[i]}]++;
    }    
    REP(i,1,n+1){
        cout<<M[{a[i],b[i]}]<<" ";
    }
    cout<<"\n"; 
    return 0;
}