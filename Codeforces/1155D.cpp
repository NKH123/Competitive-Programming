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

map<int, int >M;
int dp[310000][3];
int32_t main(){
	ios::sync_with_stdio(false);
    int n, x;
    cin>>n>>x;
    vi a(n+1);
    REP(i,1,n+1){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=2;j++){
    		dp[i][j]=-(1e18);
    	}
    }
    dp[0][0]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
    	dp[i][0]=max(a[i],a[i]+dp[i-1][0]);
    	dp[i][1]=max({a[i]*x,a[i]*x+dp[i-1][1],a[i]*x+dp[i-1][0]});
    	dp[i][2]=max({a[i],a[i]+dp[i-1][2],a[i]+dp[i-1][1]});
    	ans=max({ans,dp[i][0],dp[i][1],dp[i][2]});
    }


    cout<<ans<<"\n";

    return 0;
}