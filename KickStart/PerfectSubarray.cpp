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
    int T=t;
    vi a;
    vi pref;
    set<int>S;
    for(int i=0;;i++){
        int ans=i*i;
        if(ans<=(1e7)){
            S.insert(ans);
        }
        else{
            break;
        }
    }
    map<int, int>M;
    while(t--){
        M.clear();
        int n;cin>>n;
        a.clear();
        a.resize(n);
        pref.clear();
        pref.resize(n+1,0);
        REP(i,0,n){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+a[i-1];
        }
        int ans=0;
        M[0]=1;
        for(int i=0;i<n;i++){
            for(auto g:S){
                int req=pref[i+1]-g;
                ans+=(M[req]);
            }
            M[pref[i+1]]++;
        }
        cout<<"Case #"<<(T-t)<<": "<<ans<<"\n";

    }

    return 0;
}