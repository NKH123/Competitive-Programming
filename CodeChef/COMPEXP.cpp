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
vector<int>a;
int n, k;
double ans=0;
void fun(int x){
    if(x==n){
        int len=1;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                len++;
            }
        }
        len=len*2;
        ans+=len;
    }
    else{
        for(int i=0;i<k;i++){
            a[x]=i;
            fun(x+1);
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t=10000000;
    while(t--){
        cin>>n>>k;
        a.resize(n);
        ans=0;
        fun(0);
        // deb("without divide");
        deb(ans);
        deb(pow(k,n));
        double fin=ans*1.0/(pow(k,n));
        deb(fin);
    }


    return 0;
}