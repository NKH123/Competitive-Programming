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
int gcd(int a, int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n)cin>>a[i];
    vi l(n),r(n);
    l[0]=a[0];
    r[n-1]=a[n-1];
    for(int i=1;i<n;i++){
        l[i]=gcd(l[i-1],a[i]);
    }

    for(int i=n-2;i>=0;i--){
        r[i]=gcd(r[i+1],a[i]);
    }
    // deb(l);
    // deb(r);
    int ans=1;
    ans=max(ans,r[1]);
    ans=max(ans,l[n-2]);
    for(int i=1;i<(n-1);i++){
        ans=max(ans,gcd(l[i-1],r[i+1]));
    }
    cout<<ans<<"\n";



	return 0;
}