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

bool comp(pair<pair<int, int> , int > a, pair<pair<int, int> , int > b){
    return a.S>b.S;
}
int dp[105][105];
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    // vi S,E,L;
    int T=t;
    vector<pair<pair<int, int> , int > >sel;

    while(t--){
        int n;
        cin>>n;
        sel.resize(n);
        memset(dp,0,sizeof(dp));
        REP(i,0,n){
            int A, B, C;
            cin>>A>>B>>C;
            sel[i].F={A,B};
            sel[i].S=B;
        }
        sort(sel.begin(),sel.end(),comp);
        int ans=-1;
        for(int i=0;i<n;i++){
            dp[i][0]=sel[i].F.S;
            for(int j=1;j<=i;j++){
                for(int k=0;k<i;k++){
                    dp[i][j]=max(dp[i][j],dp[k][j-1]+max(sel[i].F.S-j*sel[i].F.F*sel[i].S,0LL));   
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        cout<<"Case #"<<T-t<<": "<<ans<<"\n";

    }



	return 0;
}