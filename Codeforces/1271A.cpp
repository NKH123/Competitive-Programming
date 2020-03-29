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
int get2(int a, int b, int c, int d, int e, int f){
	int B=min({b,c,d});
	
	b-=B;
	c-=B;
	d-=B;
	int A=min(a,d);
	return (A*e+B*f);
}
int get1(int a, int b, int c, int d, int e, int f){
	int A=min(a,d);
	a-=A;
	d-=A;
	int B=min({b,c,d});
	return (A*e+B*f);
}
int32_t main(){
    ios::sync_with_stdio(false);
    int a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;
    int ans=get1(a,b, c, d, e, f);
    ans=max(ans,get2(a,b, c, d, e, f));
    cout<<ans<<"\n";

    return 0;
}