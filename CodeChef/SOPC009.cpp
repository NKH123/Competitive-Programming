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
    vector<string>a;
    multiset<string>M;
    set<string>S;
    while(t--){
        int n, d;
        cin>>n>>d;
        a.clear();
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        S.clear();
        M.clear();
        for(int i=0;i<d;i++){
            S.insert(a[i]);
            M.insert(a[i]);
        }
        int ans=S.size();
        int l=0, r=d-1;
        while(r<n){
            l++;
            M.erase(M.find(a[l-1]));
            if(M.find(a[l-1])==M.end()){
                S.erase(a[l-1]);
            }
            r++;
            if(r==n){
                break;
            }
            M.insert(a[r]);
            S.insert(a[r]);
            ans=max((int)S.size(),ans);
        }
        cout<<ans<<"\n";

    }

    return 0;
}