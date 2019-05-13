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


int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>a[2];
    a[1].resize(n);
    a[0].resize(n);
    REP(i,0,n){
        cin>>a[0][i];
    }
    REP(i,0,n){
        cin>>a[1][i];
    }
    vector<int>par[2];
    par[0].resize(n+2,0);
    par[1].resize(n+2,0);
    for(int i=0;i<n;i++){
        par[0][i+1]=par[0][i]+a[0][i];
    }
    for(int i=n;i>=1;i--){
        par[1][i]=par[1][i+1]+a[1][i-1];
    }
    // deb(par[0]);
    // deb(par[1]);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,par[0][i]+par[1][i]);
    }
    // deb(ans);
    cout<<ans<<"\n";



	return 0;
}