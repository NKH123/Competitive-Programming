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


int dp[1005][(1LL<<13)];
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vi a(m+1);
    vi mask(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>a[i];
        int B;
        cin>>B;
        for(int j=0;j<B;j++){
            int T;
            cin>>T;
            T--;
            mask[i]=mask[i]|(1LL<<T);
        }
    }
    int finalmask=(1<<n)-1;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=m;i++){
        for(int j=1;j<=finalmask;j++){
            dp[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        int Mask=mask[i];
        for(int j=0;j<=finalmask;j++){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=0;j<=finalmask;j++){
            dp[i][Mask|j]=min({dp[i][Mask|j],a[i]+dp[i-1][j],dp[i-1][Mask|j]});
        }
    }
    int ans=dp[m][finalmask];
    if(ans>=(1e18)){
        cout<<-1<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }




    return 0;
}