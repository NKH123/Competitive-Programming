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
int gcd(int a, int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int lcm(int a,int b){
    int ans=a*b;
    int div=gcd(a,b);
    ans=ans/div;
    return ans;
}
int32_t main(){
	ios::sync_with_stdio(false);
    int a, b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    int k;
    int ans=lcm(a,b);
    k=0;
    for(int i=1;i*i<=(b-a);i++){
        if((b-a)%i==0){
            int K=i-a%i;
            if(lcm(a+K,b+K)<ans){
                k=K;
                ans=lcm(a+K,b+K);
            }
            K=(b-a)/(i)-(a%((b-a)/(i)));
            if(lcm(a+K,b+K)<ans){
                k=K;
                ans=lcm(a+K,b+K);
            }


            // int I=(b-a)/i;
        }
    }
    cout<<k<<"\n";
    return 0;
}