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
vi c;
vi d;
vi cpar;
vi dpar;

int32_t main(){
	ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        int n, a;
        cin>>n>>a;
        c.resize(n+1);
        d.resize(n+1);
        REP(i,1,n+1)cin>>c[i];
        REP(i,1,n+1)cin>>d[i];
        cpar.resize(n+1);
        dpar.resize(n+1);
        cpar[0]=0;
        dpar[0]=0;
        for(int i=1;i<=n;i++){
            cpar[i]=cpar[i-1]+c[i];
            dpar[i]=dpar[i-1]+d[i];
        }
        int ans=-(1e18);
        for(int i=1;i<=n;i++){
            tempans=0;
            for(int j=1;j<=n;j++){
                tempans+=(j-i+1)*a;
                tempans-=(cpar[j]-cpar[i-1]);
            }
        }
    }


	return 0;
}