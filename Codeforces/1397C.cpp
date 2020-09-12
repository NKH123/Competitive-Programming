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



int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a;
    a.resize(n);
    REP(i,0,n) {
        cin>>a[i];
    }
    if(n == 1) {
        cout<<"1 1\n";
        cout<<(-a[0])<<"\n";

        cout<<"1 1\n";
        cout<<(0)<<"\n";

        cout<<"1 1\n";
        cout<<(0)<<"\n";

        return 0;
    }
    cout<<1<<" "<<n-1<<"\n";
    int x = n-1;
    for(int i=0; i<(n-1);i++) {
        int cur = a[i]%n;
        int add = cur*x;
        cout<<add<<" ";
        a[i]+=add;
    }
    cout<<"\n";
    cout<<2<<" "<<n<<"\n";
    for(int i=1; i<(n);i++) {
        int cur = a[i]%n;
        int add = cur*x;
        cout<<add<<" ";
        a[i]+=add;
    }
    cout<<"\n";
    cout<<1<<" "<<n<<"\n";
    for(int i=0; i<n;i++) {
        int div = a[i]/n;
        int add = div*n;
        add = -add;
        cout<<add<<" ";
    }
    cout<<"\n";

    return 0;
}