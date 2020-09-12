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


bool comp (int A, int B) {
    return A>B;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    vi ans;
    vi used;
    while(t--) {
        int n;
        cin>>n;
        a.resize(n);
        ans.clear();
        used.clear();
        used.resize(n, 0);
        REP(i,0,n) {
            cin>>a[i];
        }
        sort(a.begin(), a.end(), comp);
        ans.push_back(a[0]);
        used[0] = 1;
        int cur = a[0];
        for(int i=1; i<n; i++) {
            int cur_gcd = 0;
            int I = -1;
            for(int j=0; j<n;j++) {
                if(used[j] == 1) continue;
                int temp =__gcd(cur, a[j]);
                if (temp > cur_gcd) {
                    I = j;
                    cur_gcd = temp;
                }
            }
            used[I] = 1;
            ans.push_back(a[I]);
            cur = cur_gcd;
        }
        for(int i=0; i<n; i++) {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}