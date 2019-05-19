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

int dp[100005];
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
int mul(int a, int b){
    int ans=0;
    ans=(((a)%mod)*(b%mod))%mod;
    return ans;
}
int add(int a, int b){
    a=a%mod;
    b=b%mod;
    int sum=(a+b)%mod;
    return sum;
}
int sub(int a, int b){
    // deb(a);
    // deb(b);
    a=a%mod;
    b=b%mod;
    int ans=a-b;
    while(ans<0){
        ans+=mod;
    }
    return ans%mod;
}

int32_t main(){
	ios::sync_with_stdio(false);
    // while(1){
    int n, k;
    memset(dp,0,sizeof(dp));

    cin>>n>>k;
    // n=(n+1)/2;
    if(n==1)n=2;
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=sub(add(mul(k,dp[i-1]),power(k,((i+1)/2))),dp[((i+1)/2)]);
    }
    // for(int i=0;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<"\n";
    // int ans=sub(power(k,n),dp[n]);
    int ans=sub(dp[n],mul(k,dp[n-1]));
    // int two=power(2,mod-2);
    // ans=mul(ans,two);
    cout<<ans<<"\n";

// }


	return 0;
}