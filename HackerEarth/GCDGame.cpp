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


int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    int dp[n+10][3];
    dp[0][0]=a[0]-1;
    dp[0][2]=a[0]+1;
    dp[0][1]=a[0];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                dp[i][j]=max(__gcd(a[i]-1,dp[i-1][0]),max(__gcd(a[i]-1,dp[i-1][1]),__gcd(a[i]-1,dp[i-1][2])));
            }
            else if(j==1){
                dp[i][j]=max(__gcd(a[i],dp[i-1][0]),max(__gcd(a[i],dp[i-1][1]),__gcd(a[i],dp[i-1][2])));
            }
            else if(j==2){
                dp[i][j]=max(__gcd(a[i]+1,dp[i-1][0]),max(__gcd(a[i]+1,dp[i-1][1]),__gcd(a[i]+1,dp[i-1][2])));
            }
        }
    }
    int ans=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    cout<<ans<<"\n";
	return 0;
}