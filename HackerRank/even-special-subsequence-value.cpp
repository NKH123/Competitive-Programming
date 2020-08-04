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


vector<vector<int> >dp;
vector<int>a;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        a.clear();
        int n;
        cin>>n;
        dp.clear();
        dp.resize(n+1, vector<int>(n+1, 0));
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        // memset(dp,0,sizeof(dp));
        int ans= 0;
        for(int i=0;i<(n-1);i++){
            if(a[i]%2 == a[i+1]%2){
                dp[i][i+1]=abs(a[i]-a[i+1]);
            }
            ans = max(ans, dp[i][i+1]);
        }
        for(int len = 3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int l = i, r= i+len-1;
                dp[l][r]=max(dp[l+1][r], dp[l][r-1]);
                if(a[l]%2 == a[r]%2){
                    dp[l][r]=max(dp[l][r], abs(a[l] - a[r]) + dp[l+1][r-1]);
                }
                ans=max(ans, dp[l][r]);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}