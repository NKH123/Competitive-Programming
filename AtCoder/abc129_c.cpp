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

int dp[100005];
set<int> a;
int n;
int fun(int x){
    if(x==0){
        return dp[x]=1;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    else{
        int ans=0;
        if(a.find(x-1)==a.end()){
            if((x-1)>=0)
            ans=(ans+fun(x-1))%mod;
        }
        if(a.find(x-2)==a.end()){
            if((x-2)>=0)
            ans=(ans+fun(x-2))%mod;
        }
        return dp[x]=ans;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));
    int m;
    cin>>n;
    cin>>m;
    REP(i,0,m){
        int A;
        cin>>A;
        a.insert(A);
    }
    cout<<fun(n)<<"\n";
    return 0;
}