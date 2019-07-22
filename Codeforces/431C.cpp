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
int n, k, d;
int dp[110][2];
int fun(int N, int f){
    if(dp[N][f]!=-1){
        return dp[N][f];
    }
    if(N==0){
        if(f==1){
            return dp[N][f]=1;
        }
        else{
            return dp[N][f]=0;
        }
    }
    else{
        int ans=0;
        for(int i=1;i<=k;i++){
            if(f==1){
                if(N>=i){
                    ans=(ans+fun(N-i,1))%mod;
                }
            }
            else{
                if(N>=i){
                    if(i<d){
                        ans=(ans+fun(N-i,0))%mod;
                    }
                    else{
                        ans=(ans+fun(N-i,1))%mod;
                    }
                }
            }
        }
        return dp[N][f]=ans;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));
    cin>>n>>k>>d;
    int ans=fun(n,0);
    cout<<ans<<"\n";
    return 0;
}