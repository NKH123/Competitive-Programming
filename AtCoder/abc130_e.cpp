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
int n, m;
vi a, b;
int dp[3000][3000];
int fun(int N, int M){
    if(dp[N][M]!=-1){
        return dp[N][M];
    }
    if(N==0 || M==0){
        return dp[N][M]=1;
    }
    else{
        int ans=0;
        ans=(fun(N-1,M)+fun(N,M-1)-fun(N-1,M-1)+mod+mod+mod)%mod;
        if(a[N-1]==b[M-1]){
            ans=(ans+fun(N-1,M-1))%mod;
        }
        return dp[N][M]=ans;
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    a.resize(n);
    b.resize(m);
    REP(i,0,n){
        cin>>a[i];
    }
    REP(i,0,m){
        cin>>b[i];
    }
    int ans=fun(n,m);
    cout<<ans<<"\n";
    return 0;
}