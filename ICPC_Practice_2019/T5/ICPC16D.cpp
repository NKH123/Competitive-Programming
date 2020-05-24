#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(NULL), cin.tie(0),cout.tie(0)
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



int n;
int ans=0;
vector<int> a(750000);
const int mod = 1e9+7;
int dp[800005];
signed main() {
    fast;
    int t;
    cin>>t;
    vector<int>ct;
    while(t--){
        cin>>n;
        a.clear();
        ct.clear();
        ct.resize(750005);
        a.resize(n);
        int maxi=-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ct[a[i]]++;
            maxi=max(a[i],maxi);
        }
        sort(a.begin(),a.end());
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=750000;i++){
            if(ct[i]){
                dp[i]=(dp[i]+1)%mod;
                for(int j=2*i;j<=750000;j+=(i)){
                    dp[j]=(dp[j]+dp[i])%mod;
                }
                ans=(ans+dp[i])%mod;
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    
    
    return 0;
}


