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
vi adj[100005];
bool vis[100005];
int ct=0;
void dfs(int v){
    ct++;
    vis[v]=true;
    for(auto g:adj[v]){
        if(!vis[g]){
            dfs(g);
        }
    }
}


int32_t main(){
	ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    memset(vis,false,sizeof(vis));
    int ans=power(n,k);
    for(int i=0;i<(n-1);i++ ){
        int A,B,C;
        cin>>A>>B>>C;
        A--;
        B--;
        if(C==0){
            adj[A].PB(B);
            adj[B].PB(A);
        }
    }
    // deb(ans);
    for(int i=0;i<n;i++){
        ct=0;
        if(!vis[i]){
            // deb(i);
            dfs(i);
            // deb(ct);
            int diff=power(ct,k);
            // deb(diff);
            ans=ans-diff;
            if(ans<0){
                ans+=mod;
            }
        }
    }
    cout<<ans<<"\n";



	return 0;
}