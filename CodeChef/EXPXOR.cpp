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

// double dp[2][100005];
vector<vector<double> >dp(2);
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi b;
    vector<double>p;
    while(t--){
        int n;
        cin>>n;
        dp[0].resize(n+1);
        dp[1].resize(n+1);
        b.resize(n+1);
        p.resize(n+1);
        b[0]=0;
        p[0]=1;
        REP(i,1,n+1){
            cin>>b[i];
        }
        REP(i,1,n+1){
            cin>>p[i];
        }
        double ans=0;
        // deb(b);
        // deb(p);
        for(int i=0;i<=30;i++){
            // memset(dp,0,sizeof(dp));
            // deb(i);
            dp[0][0]=1;
            dp[1][0]=0;
            for(int j=1;j<(n+1);j++){
                // deb(j);
                int bit=(b[j])&(1L<<i);
                // deb(bit);
                if(bit!=0){
                     // cout<<i<<" "<<j<<"\n";        
                    // dp[0][j]=p[j]*dp[1][j-1]+(1-p[j])*dp[0][j-1];
                    dp[1][j]=p[j]*dp[0][j-1]+(1-p[j])*dp[1][j-1];
                    // dp[1][j]=1-dp[0][j];
                    dp[0][j]=1-dp[1][j];
                }
                else{
                    // dp[0][j]=p[j]*dp[0][j-1]+(1-p[j])*dp[1][j-1];
                    // dp[1][j]=p[j]*dp[1][j-1]+(1-p[j])*dp[0][j-1];
                    dp[0][j]=dp[0][j-1];
                    dp[1][j]=dp[1][j-1];
                }
            }
           // deb(dp[0]);
           // deb(dp[1]);
            // deb(dp[1][n]);
            ans+=(1L<<i)*(1*dp[1][n]+0*dp[0][n]);
        }
        printf("%0.9f\n",ans);


    }



	return 0;
}