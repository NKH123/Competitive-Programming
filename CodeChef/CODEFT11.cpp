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

int fact[4000100];
int power(int a, int b){
    if(b==0){
        return 1LL;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans)%mod;
        if(b%2==1){
            ans=(a*ans)%mod;
        }
        return ans;
    }
}
int nCr(int N,int K){
    int n=N;
    int ans=fact[n];
    ans=(ans*power(fact[K],mod-2))%mod;
    ans=(ans*power(fact[n-K],mod-2))%mod;
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    fact[0]=1;
    for(int i=1;i<4000100;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    while(t--){
        int x, y, x1, y1;
        cin>>x>>y>>x1>>y1;
        int X=abs(x-x1);
        int Y=abs(y-y1);
        int N=X+Y;
        int R=X;
        int ans=nCr(N,R);
        cout<<ans<<"\n";
    }



    return 0;
}