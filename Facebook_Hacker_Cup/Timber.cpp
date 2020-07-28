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

#define  deb(x) cerr << #x << " = " << x << endl;


vector<pair<int, int> >ph;
map<int, int>dp;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    while(t--){
        dp.clear();
        int n;
        cin>>n;
        ph.clear();
        ph.resize(n);
        REP(i,0,n){
            cin>>ph[i].first;
            cin>>ph[i].second;
        }
        sort(ph.begin(),ph.end());
        // deb(ph);
        for(int i=0;i<n;i++){
            // deb(i);
            // deb(ph[i]);
            int preval = dp[ph[i].first];
            // deb(dp[ph[i].first]);
            // deb(dp[ph[i].first-ph[i].second]);
            // deb(ph[i].second);
            dp[ph[i].first]=max(dp[ph[i].first],(dp[ph[i].first-ph[i].second] + ph[i].second));
            dp[ph[i].first + ph[i].second]= max(dp[ph[i].first + ph[i].second],(preval + ph[i].second));
            // deb(dp);
            // deb("*******************");
        }
        // deb(dp);
        int ans = 0;
        for(auto g:dp){
            ans=max(ans,g.second);
        }
        cout<<"Case #"<<(T-t)<<": "<<ans<<"\n";


    }

    return 0;
}