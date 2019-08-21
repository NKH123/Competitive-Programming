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


int dp[100010][2][2][2];
int32_t main(){
    ios::sync_with_stdio(false);
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    vi c(n);
    REP(i,0,n)cin>>a[i];
    REP(i,0,n)cin>>b[i];
    REP(i,0,n)cin>>c[i];
    dp[0][0][0][1]=c[0];
    dp[0][0][1][0]=b[0];
    dp[0][1][0][0]=a[0];
    for(int i=1;i<n;i++){
        dp[i][1][0][0]=a[i]+max({dp[i-1][0][1][0],dp[i-1][0][0][1]});
        dp[i][0][1][0]=b[i]+max({dp[i-1][1][0][0],dp[i-1][0][0][1]});
        if(i==1){
            dp[i][0][1][0]=max({dp[i][0][1][0],b[i]+dp[i-1][0][1][0]});
        }
        else{
            dp[i][0][1][0]=max(dp[i][0][1][0],b[i]+b[i-1]+max(dp[i-2][1][0][0],dp[i-2][0][0][1]));
        }
        dp[i][0][0][1]=c[i]+max({dp[i-1][1][0][0],dp[i-1][0][1][0]});
        if(i<=2){
            dp[i][0][0][1]=max(dp[i][0][0][1],c[i]+dp[i-1][0][0][1]);
        }
        else{
            int maxi=dp[i][0][0][1];
            int ele=c[i]+c[i-1];
            maxi=max({maxi,ele+max({dp[i-2][1][0][0],dp[i-2][0][1][0]})});
            ele=c[i]+c[i-1]+c[i-2];
            maxi=max({maxi,ele+max({dp[i-3][1][0][0],dp[i-3][0][1][0]})});
            dp[i][0][0][1]=maxi;
        }
    }
    int ans=max({dp[n-1][1][0][0],dp[n-1][0][1][0],dp[n-1][0][0][1]});
    cout<<ans<<"\n";
    return 0;
}