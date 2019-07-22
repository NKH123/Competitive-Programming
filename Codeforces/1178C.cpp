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
#define mod 998244353

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


// int dp[1005][1005][5];
int dp[1005][1005];
int32_t main(){
    ios::sync_with_stdio(false);
    int w, h;
    cin>>w>>h;
    memset(dp,0,sizeof(dp));
    // dp[1][1][0]=1;
    // dp[1][1][1]=1;
    // dp[1][1][2]=1;
    // dp[1][1][3]=1;

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(i==1 && j==1){
                dp[i][j]=1;
            }
            else{
                if(i==1 || j==1){
                    if(i==1){
                        dp[i][j]=(2*dp[i][j-1])%mod;
                    }
                    else if(j==1){
                        dp[i][j]=(2*dp[i-1][j])%mod;
                    }
                }
                else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                }
            }        
        }
    }
    int ans=(4*dp[h][w])%mod;
    cout<<ans<<"\n";


    return 0;
}