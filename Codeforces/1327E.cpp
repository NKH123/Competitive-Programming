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
#define mod 998244353
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
int power(int a, int b){
    if(b==0){
        return 1LL;
    }
    else{
        int ans=power(a,b/2);
        ans=((ans%mod)*(ans%mod) )%mod;
        if(b%2==1){
            ans=(ans*a)%mod;
        }
        return ans;
    }
}

int mul(int a, int b){
    int ans=((a%mod)*(b%mod))%mod;
    return ans;
}
int add(int a, int b){
    int ans=(a+b)%mod;
    return ans;
}
int sub(int a, int b){
    int ans=(a%mod-b%mod+2*mod)%mod;
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi A;
    if(n==1){
        cout<<10<<"\n";
        return 0;
    }
    for(int i=1;i<n-1;i++){
        int ans=0;
        ans=add(ans,mul(mul(2,90),power(10,n-i-1)));
        ans=add(ans,mul(n-i-1,mul(power(10,n-i-2),810) ));
        A.PB(ans);

    }
    A.PB(180);
    A.PB(10);
    REP(i,0,n){
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    return 0;
}