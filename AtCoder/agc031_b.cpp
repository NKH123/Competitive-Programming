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

int ct[200010];
vi ind[200010];
int upd[200010];
int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a;
    memset(ct,0,sizeof(ct));
    memset(upd,0,sizeof(upd));
    a.PB(-1);
    REP(i,1,n+1){
        int A;
        cin>>A;
        if(A!=a[a.size()-1]){
            a.PB(A);
        }
    }
    int sz=a.size();
    vi dp;
    dp.clear();
    dp.resize(sz+1);
    dp[0]=1;
    int ans=1;
    for(int i=1;i<=sz;i++){
        dp[i]=dp[i-1];
        // if(ct[a[i]]){
        //     for(int j=0;j<ind[a[i]].size();j++){
        //         dp[i]=(dp[i]+(dp[ind[a[i]][j]-1]))%mod;
        //     }
        // }
        dp[i]=(dp[i]+upd[a[i]])%mod;
        upd[a[i]]=(upd[a[i]]+dp[i-1])%mod;
        ct[a[i]]++;
        ind[a[i]].PB(i);
    }
    cout<<dp[sz]<<"\n";


	return 0;
}