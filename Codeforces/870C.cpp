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
map<int, int>dp;
int fun(int n){
    // deb(n);
    if(dp.count(n)!=0){
        return dp[n];
    }
    if(n<4 || n==5){
        return dp[n]=-1;
    }
    if(n==4 || n==6 || n==9){
        return dp[n]=1;
    }
    else{
        int ans=-1;
        // ans=max(1+fun(n-4),1+fun(n-6));
        int A=fun(n-4);
        if(A!=-1){
            ans=1+A;
        }
        A=fun(n-6);
        if(A!=-1){
            ans=max(ans,1+A);
        }
        A=fun(n-9);
        if(A!=-1){
            ans=max(ans,1+A);
        }
        return dp[n]=ans;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int ans=0;
        int k=0;
        if(n>1000){
            k=(n-1000)/4;
            ans+=k;
            ans+=fun(n-4*k);
            cout<<ans<<"\n";
        }
        else{
            cout<<fun(n)<<"\n";
        }
    }



    return 0;
}