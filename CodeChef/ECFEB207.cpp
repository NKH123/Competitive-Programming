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

int fact[1000005];
int add(int a,int b){
    return (a+b)%mod;
}
int mul(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}
int power(int a, int b){
    if(b==0){
        return 1LL; 
    }
    else{
        int c=power(a,b/2);
        c=((c%mod)*(c%mod) )%mod;
        if(b%2==1){
            c=( (a%mod)*(c%mod) )%mod;
        }
        return c;
    }
}
int nCk(int n, int k){
    int ans=fact[n];
    ans=mul(fact[n],power(fact[n-k],mod-2));
    ans=mul(ans,power(fact[k],mod-2));
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int n, m, p;
    cin>>n>>m>>p;
    fact[0]=1;
    REP(i,1,1000005){
        fact[i]=mul(i,fact[i-1]);
    }
    if(m==1){
        cout<<power(p,n)<<"\n";
        return 0;
    }
    int ans=0;
    for(int i=1;i<=min(n,p);i++){
        int temp=0;
        temp+=mul(1,nCk(n,min(i,n)));
        // deb(temp);
        temp=mul(temp,fact[min(i,n)]);
        // deb(temp);
        temp=mul(temp,power(i,n-min(n,i)));
        // deb(temp);
        // temp+=(nCk(n,min(n,i)));
        temp=mul(temp,temp);
        // deb(temp);
        temp=mul(temp,nCk(p,min(i,n)));
        // deb(temp);
        // deb(i);
        ans=add(ans,mul(temp,power(min(i,n),(n*(m-2)))));
        // deb(ans);
    }
    cout<<ans<<"\n";

    return 0;
}


