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


int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int> >dp(n,vector<int>(2,0));
    vector<vector<int> >h(n,vector<int>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>h[j][i];
        }
    }
    dp[0][0]=h[0][0];
    dp[0][1]=h[0][1];
    int ans=max(dp[0][0],dp[0][1]);
    for(int i=1;i<n;i++){
        dp[i][0]=h[i][0]+dp[i-1][1];
        if(i>=2){
            dp[i][0]=max(dp[i][0],h[i][0]+max(dp[i-2][0],dp[i-2][1]));
        }
        dp[i][1]=h[i][1]+dp[i-1][0];
        if(i>=2){
            dp[i][1]=max(dp[i][1],h[i][1]+max(dp[i-2][0],dp[i-2][1]));
        }
        ans=max(ans,max(dp[i][0],dp[i][1]));
    }
    cout<<ans<<"\n";
    return 0;
}