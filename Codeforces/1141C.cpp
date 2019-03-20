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


int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi p(n-1);
    REP(i,0,n-1){
        cin>>p[i];
    }
    vi a(n);
    a[0]=1;
    set<int>ss;
    int mini=1e18;
    mini=min(mini,a[0]);
    for(int i=1;i<n;i++){
        a[i]=a[i-1]+p[i-1];
        mini=min(mini,a[i]);
    }
    // deb(a);

    int add=1-mini;
    // deb(mini);
    // deb(add);
    REP(i,0,n){
        a[i]+=add;
        ss.insert(a[i]);
    }
    // deb(a);
    vi b(ss.begin(),ss.end());
    // deb(b);
    int f=1;
    if(b.size()!=n){
        cout<<-1<<"\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        if(b[i]!=(i+1)){
            f=0;
            break;
        }
    }
    if(f){
        REP(i,0,n){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<-1<<"\n";
        // return 0;
    }



	return 0;
}