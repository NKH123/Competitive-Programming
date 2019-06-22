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


int n;
vi a;
bool comp(pi A, pi B){
    int aa=A.F;
    int bb=B.F;
    aa=-aa-1;
    bb=-bb-1;
    return abs(aa)<abs(bb);
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    REP(i,0,n)cin>>a[i];
    vector<pair<int,int> >b;
    for(int i=0;i<n;i++){
        b.PB({a[i],i});
    }
    REP(i,0,n){
        if(b[i].F<0){
            b[i].F=-1-b[i].F;
        }
    }
    sort(b.begin(),b.end(),comp);
    if(b.size()%2==0){
        for(int i=0;i<n;i++){
            b[i].F=-b[i].F-1;
        }
    }
    else{
        for(int i=1;i<n;i++){
            b[i].F=-b[i].F-1;
        }
    }
    vi ans(n);
    for(int i=0;i<n;i++){
        ans[b[i].S]=b[i].F;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";




    return 0;
}