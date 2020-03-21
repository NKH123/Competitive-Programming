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


char a[105][105];
int dp[105][105];
int32_t main(){
    ios::sync_with_stdio(false);
    int h, w;
    cin>>h>>w;
    REP(i,0,h){
        REP(j,0,w){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            dp[i][j]=1e18;
        }
    }
    if(a[0][0]=='#'){
        dp[0][0]=1;
    }
    else{
        dp[0][0]=0;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0 && j==0){
                continue;
            }
            if(a[i][j]=='#'){
                if(i!=0){
                    dp[i][j]=min(dp[i][j],((a[i-1][j]=='.')?1:0) + dp[i-1][j]);
                }
                if(j!=0){
                    dp[i][j]=min(dp[i][j],((a[i][j-1]=='.')?1:0) +dp[i][j-1]);
                }
            }
            else{
                if(i!=0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]);
                }
                if(j!=0){
                    dp[i][j]=min(dp[i][j],dp[i][j-1]);
                }
            }
        }
    }

    cout<<dp[h-1][w-1]<<"\n";

    return 0;
}