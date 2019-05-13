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
int fun(int n){
    if(n==0){
        return dp[n]=0;
    }
    if(n==1){
        return dp[n]=1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    else{
        int A=1+fun(n-1);
        int mul=6;
        int B=1e18;
        while(n-mul>=0){
            B=min(B,1+fun(n-mul));
            mul*=6;
        }
        mul=9;
        int C=1e18;
        while(n-mul>=0){
            C=min(C,1+fun(n-mul));
            mul*=9;
        }
        return dp[n]=min(A,min(B,C));
    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<fun(n)<<"\n";



	return 0;
}