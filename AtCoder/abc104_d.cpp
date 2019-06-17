#include<bits/stdc++.h>
using namespace std;
#define F first
// #define S second
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
string S;
int dp[100005][4];
int power(int a, int b){
    if(b==0){
        return 1;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans)%mod;
        if(b%2){
            ans=((a%mod)*(ans%mod))%mod;
        }
        return ans;
    }
}
int add(int A, int B){
    int res=(A%mod)+(B%mod);
    res=res%mod;
    return res;
}
int mul(int A, int B){
    A=A%mod;
    B=B%mod;
    int res=(A*B)%mod;
    return res;
}
int div(int A, int B){
    int res=A%mod;
    res=(res*(power(B,mod-2)))%mod;
    return res;
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>S;
    memset(dp,0,sizeof(dp));
    int ct=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='?')ct++;
    }
    dp[0][0]=1;
    for(int i=0;i<S.size();i++){
        if(S[i]=='?'){
            for(int j=0;j<4;j++){
                dp[i+1][j]=mul(dp[i][j],3);
            }
        }
        else{
            for(int j=0;j<4;j++){
                dp[i+1][j]=dp[i][j];
            }
        }
        if(S[i]=='A' || S[i]=='?'){
            dp[i+1][1]=add(dp[i+1][1],dp[i][0]);
        }
        if(S[i]=='B' || S[i]=='?'){
            dp[i+1][2]=add(dp[i+1][2],dp[i][1]);
        }
        if(S[i]=='C' || S[i]=='?'){
            dp[i+1][3]=add(dp[i+1][3],dp[i][2]);
        }
    }
    cout<<dp[S.size()][3]<<"\n";
    return 0;
}