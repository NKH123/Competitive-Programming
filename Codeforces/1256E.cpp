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


int dp[200005][3];
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n+1);
    REP(i,1,n+1){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<=n;i++){
        for(int j=0;j<3;j++){
            if(i!=0)
                dp[i][j]=1e18;
            else{
                dp[i][j]=0;
            }
        }
    }
    for(int i=3;i<=n;i++){
        for(int j=3;j<=5;j++){
            int ind=i-j;
            if(ind<0){
                continue;
            }
            int mini=1e18;
            dp[i][j-3]=min({dp[ind][0],dp[ind][1],dp[ind][2]})+a[i]-a[ind+1];
        }
    }
    int ans=min({dp[n][0],dp[n][1],dp[n][2]});
    cout<<ans<<"\n";
    return 0;
}