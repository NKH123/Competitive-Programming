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



int32_t main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    vi c(k*n);
    map<int, int>Ct;
    REP(i,0,k*n){
        cin>>c[i];
        Ct[c[i]]++;
    }
    vi f(n);
    map<int, int>Ctf;
    REP(i,0,n){
        cin>>f[i];
        Ctf[f[i]]++;
    }
    vi h(k+1);
    REP(i,1,k+1){
        cin>>h[i];
    }
    h[0]=0;
    int ans=0;
    for(auto g:Ctf){
        if(g.S==1){
            int ava=min(Ct[g.F],k);
            ans+=(h[ava]);
        }
        else{
            int total=Ct[g.F];
            int N=g.S;
            int dp[N+1][k+1][total+1];
            memset(dp,0,sizeof(dp));
            int temp=0;
            for(int i=1;i<=N;i++){
                if(i==1){
                    int limit=min(total,k);
                    for(int j=0;j<=limit;j++){
                        dp[i][j][j]=h[j];
                        temp=max(temp,dp[i][j][j]);
                    }   
                }
                else{
                    int limit=min(total,k);
                    for(int j=0;j<=limit;j++){
                        for(int k=j;k<=total;k++){
                            for(int I=0;I<=limit;I++){
                                dp[i][j][k]=max(dp[i][j][k],dp[i-1][I][k-j]+h[j]);
                                temp=max(temp,dp[i][j][k]);
                            }
                        }
                    }
                }
            }
            ans+=temp;
        }
    }
    cout<<ans<<"\n";




    return 0;
}