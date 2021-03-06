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



int32_t main(){
    ios::sync_with_stdio(false);
    int n, b;
    cin>>n;
    cin>>b;
    int B=b;
    set<int>primes;

    while(b%2==0){
        primes.insert(2);
        b/=2;
    }
    for(int i=3;i*i<=b;i+=2){
        while(b%i==0){
            primes.insert(i);
            b/=i;
        }
    }
    if(b>1){
        primes.insert(b);
    }
    int ans=1e18;
    // deb(primes);
    for(auto g:primes){
     int temp=0;
     int N=n;
     while(N>0){
        N/=g;
        temp+=N;
    }
    int times=0;
    int BB=B;
    while(BB%g==0){
        BB/=g;
        // if(BB>0)
        times++;
    }
    // deb(temp);
    // deb(times);
    temp/=times;
    ans=min(temp,ans);
}
cout<<ans<<"\n";



return 0;
}