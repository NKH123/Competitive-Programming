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
vi adj[200005];
bool vis[200005];
int col[200005];
int f=0;
void dfs(int x, int p){
    vis[x]=true;
    for(auto g:adj[x]){
        if(vis[g]){
            if(col[g]==p){
                f=1;
            }
            else{

            }
        }
        else{
            if(p==1){
                col[g]=0;
                dfs(g,0);
            }
            else{
                col[g]=1;
                dfs(g,1);
            }       
        }
    }
}
int32_t main(){
 ios::sync_with_stdio(false);
 memset(vis,false, sizeof(vis));
 int n, m;
 memset(col,-1,sizeof(col));
 cin>>n>>m;
 vector<pair<int, int> >edges;
 REP(i,0,m){
    int A, B;
    cin>>A>>B;
    adj[A].PB(B);
    adj[B].PB(A);
    edges.PB({A,B});
}
col[1]=0;
dfs(1,0);
if(f==1){
    cout<<"NO\n";
    return 0;
}
cout<<"YES\n";
REP(i,0,m){
    int A=edges[i].F;
    int B=edges[i].S;
    if(col[A]==0){
        cout<<1;
    }   
    else{
        cout<<0;
    }
}
cout<<"\n";
return 0;
}