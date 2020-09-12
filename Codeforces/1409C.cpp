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
    int t;
    cin>>t;
    while(t--) {
        int n, x, y;
        cin>>n>>x>>y;
        int diff = y - x;
        int ans_i = -1;
        int ans_j = -1;
        int MAXI = 1e18;
        int CD = 1e18;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int diff_pos = j - i;
                if (diff % (diff_pos) != 0 ) {
                    continue;
                }
                int cd = diff/diff_pos;
                int last_element = y + (n-1 - j)*cd;
                int first_element = x - (i)*cd;
                if (last_element < MAXI && first_element >=1) {
                    MAXI =  last_element;
                    ans_i = i;
                    ans_j = j;
                    CD = cd;
                } 
            }
        }
        vi a(n);
        a[ans_i] = x;
        a[ans_j] = y;
        for(int i=ans_i - 1; i>=0; i--) {
            a[i] = a[i+1] -CD;
        }
        for(int i= ans_i+1; i<n; i++) {
            a[i] = a[i-1] + CD;
        }
        for(int i=0; i<n; i++) {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}