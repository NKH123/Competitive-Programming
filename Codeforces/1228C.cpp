#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef unsigned long long ll;
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
 
int power(int a, int b){
    if(b==0){
        return 1LL;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans)%mod;
        if((b%2)==1){
            ans=(a*ans)%mod;
        }
        return ans;
    }
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    int x, n;
    cin>>x>>n;
    // deb(n);
    set<int> primes;
    while(x%2==0){
        primes.insert(2);
        x=x/2;
    }
    for(int i=3;i*i<=x;i+=2){
        while((x%i)==0){
            primes.insert(i);
            x=x/i;
        }
    }
    if(x!=1){
        primes.insert(x);
    }
    // deb(primes);
    int ans=1;
    for(auto g:primes){
        int d=g;
        // deb(g);
        int N=n;
        while(N>0){
            // int no=n/d;
            N=N/d;
            // deb(no);
            ans=(ans*power(g,N))%mod;
 
        }
    }
    cout<<ans<<"\n";
 
 
 
    return 0;
}
