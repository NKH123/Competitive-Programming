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
bool comp(pair<int, int> a, pair<int,int> b){
    return a.S>b.S;
}

int32_t main(){
	ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vi a(n);
    REP(i,0,n)cin>>a[i];
    vi b(m),c(m);
    vector<pair<int, int> >bc;
    REP(i,0,m){
        cin>>b[i]>>c[i];
        bc.PB({b[i],c[i]});
    }
    sort(bc.begin(),bc.end(),comp);
    int I=0;
    sort(a.begin(),a.end());
    // deb(bc);
    // deb(a);
    REP(i,0,m){
        // deb(i);
        // deb(I);
        // deb(bc[i].F);
        // deb(min(I+bc[i].F,n));
        int J=I;
        for(int j=I;j<min(I+bc[i].F,n);j++){
            // deb(j);
            if(a[j]>bc[i].S){
                break;
            }
            else{
                a[j]=bc[i].S;
                J++;
            }
        }
        I=J;
        // deb(i);
        // deb(a);
    }
    int sum=0;
    // deb(a);
    REP(i,0,n){
        sum+=a[i];
    }
    cout<<sum<<"\n";

    return 0;
}