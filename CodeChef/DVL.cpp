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
#define mod 987654319
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


int dp[3005][7];
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    vi ind={0,2,1,3,5,4,6};
    deb(ind);
    for(int i=0;i<n;i++){
        dp[i][0]=1;
        for(int j=0;j<i;j++){
            for(auto it:ind){
                if(it==0){
                    continue;
                }
                else if(it==2){
                    if(a[j]>a[i]){
                        dp[i][2]=(dp[i][2]+dp[j][0])%mod;
                    }
                }
                else if(it==1){
                    if(a[j]>a[i]){
                        dp[i][1]=(dp[i][1]+dp[j][2])%mod;
                    }
                }
                else if(it==3){
                    if(a[j]>a[i]){
                        dp[i][3]=(dp[i][3]+dp[j][1])%mod;
                    }
                }
                else if(it==5){
                    if(a[j]>a[i]){
                        dp[i][5]=(dp[i][5]+dp[j][3])%mod;
                    }
                }
                else if(it==4){
                    if(a[j]>a[i]){
                        dp[i][4]=(dp[i][4]+dp[j][5])%mod;
                    }
                }
                 else if(it==6){
                    if(a[j]>a[i]){
                        dp[i][6]=(dp[i][6]+dp[j][4])%mod;
                    }
                }

            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<7;k++){
            cout<<dp[i][k]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        ans=(ans+dp[i][6])%mod;
    }
    cout<<ans<<"\n";


    return 0;
}