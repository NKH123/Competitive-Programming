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
int n, m;
vector<int>prime_factor;
void pre(){
    int M=m;
    for(int i=2;i*i<=m;i++){
        int f=0;
        while(M%i==0){
            if(f==0){
                prime_factor.PB(1);
                f=1;
            }
            else{
                prime_factor[prime_factor.size()-1]++;
            }
            M=M/i;
        }
    }
    if(M>1){
        prime_factor.PB(1);
    }
}
int power(int a, int b){
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a%mod;
    }
    else{
        int ans=power(a,b/2);
        ans=(ans*ans)%mod;
        if(b%2==1){
            ans=((a%mod)*ans)%mod;
        }
        return ans;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    pre();
    int ans=1;
    vi fact(400005);
    fact[0]=1;
    for(int i=1;i<400005;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    for(int i=0;i<prime_factor.size();i++){
        int tans=fact[n-1+prime_factor[i]];
        tans=(tans*(power(fact[n-1],mod-2)%mod))%mod;
        tans=(tans*((power(fact[prime_factor[i]],mod-2))%mod))%mod;
        ans=(ans*tans)%mod;
    }
    cout<<ans<<"\n";

    return 0;
}