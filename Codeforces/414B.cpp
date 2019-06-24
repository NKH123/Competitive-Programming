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


int dp[2005][2005];
int32_t main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    vector<vector<int> >factors(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                factors[i].push_back(j);
                if(j!=(i/j)){
                    factors[i].PB(i/j);
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        if(i==0){
            for(int j=1;j<=n;j++){
                dp[j][i]=1;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                for(int K=0;K<factors[j].size();K++){
                    dp[j][i]=(dp[j][i]+dp[factors[j][K]][i-1])%mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+dp[i][k-1])%mod;
    }
    cout<<ans<<"\n";

    return 0;
}