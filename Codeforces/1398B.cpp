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

bool comp(int A, int B) {
    return A>B;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    string s;
    vi a;
    while(t--) {
        cin>>s;
        a.clear();
        int ct = 0;
        REP(i,0,s.size()){
            if (s[i]=='0'){
                if (i!=0){
                    if(s[i-1] == '1'){
                        a.PB(ct);
                    }
                }
                ct = 0;
            }
            else{
                ct++;
            }
        }
        if (ct!=0) {
            a.PB(ct);
        }
        sort(a.begin(), a.end(), comp);
        int ans = 0;
        for(int i = 0; i < a.size(); i+=2) {
            ans+=a[i];
        }
        cout<<ans<<"\n";
    }

    return 0;
}