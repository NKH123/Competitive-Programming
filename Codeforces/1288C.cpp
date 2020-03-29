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

int dp[11][1005][1005];
int par[1005][1005];
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    memset(par,0,sizeof(par));
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[0][i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            par[i][j]=dp[0][i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            par[i][j]=((par[i][j]+par[i+1][j]+par[i][j-1])%mod-par[i+1][j-1]+2*mod)%mod;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[i][j][k]=par[j][k];
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                par[j][k]=dp[i][j][k];
            }
        }
        for(int j=n;j>=1;j--){
            for(int k=1;k<=n;k++){
                par[j][k]=((par[j][k]+par[j+1][k]+par[j][k-1])%mod-par[j+1][k-1]+2*mod)%mod;
            }
        }

    }
    int ans=par[1][n];
    cout<<ans<<"\n";
    return 0;
}