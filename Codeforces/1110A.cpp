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
#define mod 2

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
    if(b==1){
        return a%mod;
    }
    if(b==0){
        return 1;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans)%mod;
        if(b%2==1){
            ans=(a*ans)%mod;
        }
        return ans;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int b, k;
    cin>>b>>k;
    vi a(k);
    REP(i,0,k)cin>>a[i];
    int ans=0;
    int po=0;
    for(int i=k-1;i>=0;i--){
        ans=(ans+a[i]*power(b,po))%2;
        po++;
    }
    if(ans==1){
        cout<<"odd\n";
    }
    else{
        cout<<"even\n";
    }
    return 0;
}