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



int32_t main(){
    ios::sync_with_stdio(false);

    // int t;
    // cin>>t;

    // while(t--){
    //     int n;
    //     cin>>n;

    // }
    vector<int>dp(1005,1e18);
    // deb(dp);
    dp[0]=0;
    map<int,int >vals;
    vals[0]=0;
    for(int i=9;i<=1000;i+=10){
        if((i%10)==9){
            for(int j=i;j<=1000;j+=i){
                int ini=dp[j];
                dp[j]=min(dp[j],dp[j-i]+1);
                if(ini>=dp[j]){
                    vals[j]=i;
                }
            }
        }
    }
    // deb(dp);
    for(int i=0;i<=1000;i++){
        if(dp[i]<1e18){
            cout<<i<<" : "<<dp[i]<<" : ";

            int cur=i;
            while(cur>0){
                cout<<vals[cur]<<" ";
                cur=cur-vals[cur];
            }
            cout<<"\n";
        }

    }

    return 0;
}