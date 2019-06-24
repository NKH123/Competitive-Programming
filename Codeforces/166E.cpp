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


vector<vector<int> >dp(2,vector<int>(4,0));
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i%2][0]=dp[i%2][1]=dp[i%2][2]=dp[i%2][3]=0;
        dp[i%2][0]=(dp[1-(i%2)][1]+dp[1-(i%2)][2]+dp[1-(i%2)][3])%mod;
        dp[i%2][1]=(dp[1-(i%2)][0]+dp[1-(i%2)][2]+dp[1-(i%2)][3])%mod;
        dp[i%2][2]=(dp[1-(i%2)][1]+dp[1-(i%2)][0]+dp[1-(i%2)][3])%mod;
        dp[i%2][3]=(dp[1-(i%2)][1]+dp[1-(i%2)][2]+dp[1-(i%2)][0])%mod;
    }
    cout<<dp[n%2][0]<<"\n";
    return 0;
}