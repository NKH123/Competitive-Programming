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
int n;
string s;
int dp[505][505];
int fun(int l, int r){
    if(l>r){
        return 0;
    }
    if(l==r){
        return 1;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    else{
        int ans=1+fun(l+1,r);
        for(int i=l+1;i<=r;i++){
            if(s[i]==s[l]){
                ans=min(ans,fun(l+1,i-1)+fun(i,r));
            }
        }
        return dp[l][r]=ans;
    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cin>>s;
    int ans=fun(0,n-1);
    cout<<ans<<"\n";
	return 0;
}