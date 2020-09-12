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

int a, b, x, y, n;

void reduce () {
    if (a < b) {
        int want = a-x;
        int valid = a-x;
        int can = min({want, n, valid});
        a -= can;
        n -= can;
    } else if (b < a){
        int want = b-y;
        int valid = b-y;
        int can = min({want, n, valid});
        b -= can;
        n -= can;
    }
}
void reduce_a() {
     int want = a-x;
        int valid = a-x;
        int can = min({want, n, valid});
        a -= can;
        n -= can;
}
void reduce_b () {
    int want = b-y;
        int valid = b-y;
        int can = min({want, n, valid});
        b -= can;
        n -= can;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        cin>>a>>b>>x>>y>>n;
        int rem_a = a-x;
        int rem_b = b-y;
        if (n >= (rem_a + rem_b)) {
            cout<<(x*y)<<"\n";
            continue;
        }
        int A, B, X, Y, N;
        A = a;
        B =b;
        X = x;
        Y = y;
        N =n;
        reduce_a();
        reduce_b();
        // deb(a);
        // deb(b);
        int ans = a*b;
        a= A;
        b = B;
        n = N;
        reduce_b();
        reduce_a();
        // deb(a);
        // deb(b);
        ans = min(a*b, ans);
        cout<<ans<<"\n";

        // Decrease more
    }

    return 0;
}