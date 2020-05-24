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
#define mod 1000000009

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


int32_t main(){
    ios::sync_with_stdio(false);
    int n, a, b, k;
    cin>>n>>a>>b>>k;
    string s;
    cin>>s;
    int ans=0;
    int ainv=power(a,k);
    ainv=power(ainv,mod-2);
    int R=(power(b,k)*(ainv))%mod;
    for(int i=0;i<k;i++){
        int B=1;
        if(s[i]=='+'){

        }
        else{
            B=-1;
        }
        ans=(ans+B*((power(a,n-i)*power(b,i))%mod)+mod+mod)%mod;
        // deb(i);
        // deb(ans);
    }
    // deb(ans);
    if(R==1){
        ans=(ans*((n+1)/k))%mod;
        cout<<ans<<"\n";
        return 0;

    }
    int n1=(power(b,n+1)-power(a,n+1)+mod+mod)%mod;
    // deb(n1);
    ans=(ans*(n1))%mod;

    n1=(power(b,k)-power(a,k)+mod+mod)%mod;
    n1=power(n1,mod-2);
    // deb(n1);
    ans=(ans*n1)%mod;
    n1=power(a,n+1-k);
    n1=power(n1,mod-2);
    // deb(n1);
    ans=(ans*n1)%mod;
    cout<<ans<<"\n";


    return 0;
}                       