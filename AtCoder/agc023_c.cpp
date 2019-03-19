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

ll power(ll x, ll y) 
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return (((x*temp)%mod)*temp)%mod; 
}
int fact[1000005];
int invfact[1000005];
int inv(int N){
    return power(N,mod-2);
}
ll nCr(ll n, ll r){
    if(r<0 || n<0)return 0;
    if(n<r) return 0;
    ll a=fact[n];
    a=(a*invfact[r])%mod;
    a=(a*invfact[n-r])%mod;
    return a;
}
void init(){
    fact[0]=1;
    invfact[0]=1;
    for(int i=1;i<1000005;i++){
        fact[i]=(i*fact[i-1])%mod;
        invfact[i]=inv(fact[i]);
    }
}


int32_t main(){
	ios::sync_with_stdio(false);
    init();
    int n;
    cin>>n;
    ll ans=(n-1)*fact[n-1];
    ans=ans%mod;
    int k=n-2;
    deb(ans);
    for(int i=1;i*2<=k;i++){
        int cur=fact[k-i];
        cur=(cur*fact[n-1-i])%mod;
        cur=(cur*invfact[k-2*i])%mod;
        ans-=cur;
        ans=ans%mod;
    }
    if(ans<0)ans+=mod;
    cout<<ans<<"\n";



	return 0;
}