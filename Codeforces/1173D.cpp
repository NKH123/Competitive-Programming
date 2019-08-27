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
#define mod 998244353

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


vector<int>adj[200005];
int deg[200005];
int fac[500005];
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    memset(deg,0,sizeof(deg));
    fac[0]=1;
    for(int i=1;i<500005;i++){
    	fac[i]=(i*fac[i-1])%mod;
    }
    REP(i,0,n-1){
    	int A, B;
    	cin>>A>>B;
    	adj[A].PB(B);
    	adj[B].PB(A);
    	deg[A]++;
    	deg[B]++;
    }
    int ans=n;
    for(int i=1;i<=n;i++){
        	ans=(ans*(fac[deg[i]]))%mod;
    }
    cout<<ans<<"\n";




    return 0;
}