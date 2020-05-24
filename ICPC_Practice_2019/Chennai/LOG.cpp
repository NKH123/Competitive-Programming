#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
#define MOD 1000000007
#define N 100010
#define int long long 
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
bool parity(int n){
    int ans=0;
    while(n){
        ans+=(n&1);
        n>>=1;
    }
    return (ans%2);
}

signed main(){
    fast;

    int t;
    cin>>t;
    vector<int>a;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=0;
        int odd[n],even[n];
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                odd[i]=parity(a[i]);
                even[i]=1-odd[i];
            }
            else{
                odd[i]=odd[i+1]+parity(a[i]);
                even[i]=even[i+1]+parity(a[i]);
            }
        }
        int prev_odd[n]{0},prev_even[n]{0};
        memset(prev_odd,0,sizeof prev_odd);
        memset(prev_even,0,sizeof prev_even);
        prev_odd[0]=parity(a[0]);
        prev_even[0]=parity(a[0]);
        for(int i=1;i<n-1;i++){
            if(parity(a[i])){
                ans+=(prev_even[i-1]*even[i+1])%MOD;
                ans%=MOD;
                ans+=(prev_odd[i-1]*odd[i+1])%MOD;
                ans%=MOD;
            }
            else{
                ans+=(prev_even[i-1]*odd[i+1])%MOD;
                ans%=MOD;
                ans+=(prev_odd[i-1]*even[i+1])%MOD;
                ans%=MOD;
            }
            prev_odd[i]+=prev_odd[i-1]+parity(a[i]);
            prev_even[i]+=prev_even[i-1]+parity(a[i]);
        }
        cout<<ans<<endl;
    }

}


