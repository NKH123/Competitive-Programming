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


double dp[2005][2005];
int32_t main(){
    ios::sync_with_stdio(false);
    int n, t;
    double p;
    cin>>n>>p>>t;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<(2005);i++){
        dp[i][0]=0;
    }
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(i>j){
                continue;
            }
            if(i==0){
                dp[i][j]=(1-p)*(dp[i][j-1]);
            }
            else{
                if(i!=n)
                dp[i][j]=p*dp[i-1][j-1]+(1-p)*(dp[i][j-1]);
                else{
                    dp[i][j]=p*dp[i-1][j-1]+(dp[i][j-1]);
                }
            }
        }
    }
    double ans=0;
    for(int i=0;i<=n;i++){
        ans+=(i*dp[i][t]);
    }
    printf("%0.9lf\n",ans);
    // deb(n);
    // deb(t);
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=t;j++){
    //         cout<<"[ "<<i<<" "<<j<<" "<<dp[i][j]<<" ] ";
    //     }
    //     cout<<"\n";
    // }

    return 0;
}