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

vector<vector<int> >a;
vector<vector<pair<int, pair<int, int > > > >dp;
set<int>pos;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        a.clear();
        dp.clear();
        a.resize(n,vector<int>(n,0));
        dp.resize(n*n);
        pos.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                if(a[i][j]==1){
                    dp[0].PB({0,{i,j}});
                }
                else{
                    dp[a[i][j]-1].PB({1e18,{i,j}});
                }
            }
        }
        int ans=1e18;
        for(int K=1;K<k;K++){
            for(int i=0;i<dp[K].size();i++){
                for(int j=0;j<dp[K-1].size();j++){

                    dp[K][i].F=min(dp[K][i].F,abs(dp[K][i].S.F-dp[K-1][j].S.F)+abs(dp[K][i].S.S-dp[K-1][j].S.S)+dp[K-1][j].F);
                    if(K==(k-1)){
                        ans=min(ans,dp[K][i].F);
                    }
                }

            }
        }
        if(k==1){
            ans=0;
        }
        cout<<ans<<"\n";

    }

    return 0;
}