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


int dp[3005][3];
int n;
vi a;
vi b;
vi c;
int solve(int ind,  int prev){
    if(dp[ind][prev]!=-1){
        return dp[ind][prev];
    }
    int ans;
    int i=ind;
    if(ind==(n-1)){
        if(prev==1){
            // return dp[ind][cur][prev]=b[n-1];
            ans=b[n-1];
        }
        else{
            // return dp[ind][cur][prev]=a[n-1];
            ans=a[n-1];
        }
    }
    else{
        if(prev==1){
            ans=max(c[ind]+solve(ind+1,0),b[ind]+solve(ind+1,1));
        }   
        else{
            ans=max(a[i]+solve(ind+1,1),b[i]+solve(ind+1,0));
        }
    }   
    return dp[ind][prev]=ans;
}
int32_t main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    REP(i,0,n){
        cin>>a[i];
    }
    REP(i,0,n){
        cin>>b[i];
    }
    REP(i,0,n){
        cin>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    // for(int i=0;i<)
    if(n==1){
        cout<<a[0]<<"\n";
        return 0;
    }
    // int ans=max(a[i]+max({solve(1,0),solve(1)solve(1,,solve(0,1));
    // int ans=max({a[0]+max({solve(1,1,0),solve(1,2,0)}),b[0]+max({solve(1,2,1),solve(1,1,1)});
        int ans=solve(0,0);
    // int ans=a[0]+
        cout<<ans<<"\n";
        return 0;
    }