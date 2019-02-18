#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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


int main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    set<int>ss;
    vi A(n);
    REP(i,0,n){
        cin>>a[i];
        A[i]=a[i];
        ss.insert(a[i]);
    }
    //a.resize(distance(a.begin(),unique(a.begin(),a.end())));
    vi b;
    for(int i=0;i<n;i++){
        
            if(ss.find(-1*a[i])==ss.end()){
                b.PB(a[i]);
            }
        
    }
    sort(b.begin(),b.end());
    if(b.size()<3){
        cout<<0<<"\n";
        return 0;
    }
    else{
        ll ans=0;
        int comp=b[b.size()-3];
        //deb(b);
        //deb(comp);
        REP(i,0,n){
            if(A[i]<comp && A[i]>0) {
          //      deb(A[i]);
                ans=ans+A[i]+mod;
                ans=ans%mod;

            }
        }
        cout<<ans<<"\n";
    }
    




	return 0;
}