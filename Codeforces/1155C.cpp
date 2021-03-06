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
int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
map<int,int>m;
int32_t main(){
	ios::sync_with_stdio(false);
    int n, M;
    cin>>n>>M;
    vi x(n);
    REP(i,0,n){
        cin>>x[i];
    }
    vi p(M);
    REP(i,0,M){
        cin>>p[i];
        m[p[i]]=i+1;
    }
    vi y(n-1);
    REP(i,0,n-1){
        y[i]=x[i+1]-x[i];
    }
    int gap=y[0];
    for(int i=0;i<y.size()-1;i++){
        gap=gcd(gap,y[i+1]);
    }
    for(int i=0;i<M;i++){
        if(gap%p[i]==0){
            cout<<"YES\n";
            cout<<x[0]<<" "<<i+1<<"\n";
            return 0;
        }
    }
    cout<<"NO\n";


	return 0;
}