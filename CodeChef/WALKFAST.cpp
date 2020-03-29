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

vi x;
int get(int from, int to, int ti){
    int dis=abs(x[from]-x[to]);
    int T=dis*ti;
    return T;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    
    while(t--){
        int n, a, b, c, d, p, q, y;
        cin>>n>>a>>b>>c>>d>>p>>q>>y;
        x.clear();
        x.resize(n);
        REP(i,0,n){
            cin>>x[i];
        }
        a--;
        b--;
        c--;
        d--;
        int ans=get(a,b,p);
        if(get(a,c,p)<=y){              
            ans=min(ans,y+get(c,d,q)+get(d,b,p));
        }
        cout<<ans<<"\n";


        
    }

    return 0;
}