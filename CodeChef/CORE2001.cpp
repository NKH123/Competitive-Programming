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



int32_t main(){
    ios::sync_with_stdio(false);
    int m, n;
    cin>>m>>n;
    int dp[m+1][n+1][2];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        if(i%2==0){
            dp[1][i][0]=1;
        }
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<2;k++){
                //1
                int I, J;
                I=i-2;
                J=j-1;
                if(I>=1 && I<=m && J>=1 && J<=n){
                    dp[i][j][k]=(dp[i][j][k]+dp[I][J][1^k])%mod;
                }

                //2
                I=i-1;
                J=j-2;
                if(I>=1 && I<=m && J>=1 && J<=n){
                     dp[i][j][k]=(dp[i][j][k]+dp[I][J][1^k])%mod;
                }

                //3
                I=i-2;
                J=j+1;
                if(I>=1 && I<=m && J>=1 && J<=n){
                     dp[i][j][k]=(dp[i][j][k]+dp[I][J][1^k])%mod;
                }
                //4
                I=i-1;
                J=j+2;
                if(I>=1 && I<=m && J>=1 && J<=n){
                     dp[i][j][k]=(dp[i][j][k]+dp[I][J][1^k])%mod;
                }

            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        // ans+=dp[m][i][1];
        ans=(ans+dp[m][i][1])%mod;
    }
    cout<<ans<<"\n";
    return 0;
}