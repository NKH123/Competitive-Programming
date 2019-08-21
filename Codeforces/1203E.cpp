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


int dp[151000][3];
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    memset(dp,0,sizeof(dp));
    // if(a[0]==1){
    //     dp[0][0]=1;
    //     dp[0][1]=1;
    //     dp[0][2]=0;
    // }
    // else{
    //     dp[0][0]=1;
    //     dp[0][1]=1;
    //     dp[0][2]=1;
    // }
    // for(int i=1;i<n;i++){
    //     if(a[i]==a[i-1]){
    //         if(a[i]==1){
    //             dp[i][2]=0;
    //         }
    //         else{
    //             dp[i][2]=dp[i-1][2];
    //         }
    //         dp[i][0]=max(dp[i-1][0],1+dp[i-1][2]);
    //         dp[i][1]=max({1+dp[i-1][0],1+dp[i-1][2],dp[i-1][1]} );
    //     }
    //     else if(a[i]==(a[i-1]+1)){
    //         dp[i][0]=max({1+dp[i-1][0],1+dp[i-1][2],dp[i-1][1]});
    //         dp[i][1]=max({1+dp[i-1][0],1+dp[i-1][1],1+dp[i-1][2]});
    //         dp[i][2]=max({1+dp[i-1][2],dp[i-1][0]});
    //     }
    //     else{
    //         dp[i][0]=1+max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
    //         dp[i][1]=1+max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
    //         dp[i][2]=1+max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
    //     }
    // }
    // // deb({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    // // cout<<dp[n-1][0]<<" "<<dp[n-1][1]<<" "<<dp[n-1][2]<<"\n";
    // int ans=max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    // cout<<ans<<"\n";
    // set<int>used;
    vi A(151000,0);
    for(int i=0;i<n;i++){
        if(a[i]==1){
            if(A[1]==0){
                A[1]=1;
            }
            else{
                if(A[2]==0){
                    A[2]=1;
                }
            }
        }
        else{
            if(A[a[i]-1]==0){
                A[a[i]-1]=1;
            }
            else{
                if(A[a[i]]==0){
                    A[a[i]]=1;
                }
                else{
                    if(A[a[i]+1]==0)
                    A[a[i]+1]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<151000;i++){
        if(A[i]==1){
            ans++;
        }
    }
    cout<<ans<<"\n";


    return 0;
}