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
    int n, II;
    cin>>n>>II;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vi b;
    b.PB(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            b.PB(a[i]);
        }
    }
    int I=0;
    vi c(b.size(),0);
    int ct=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[I]){
            c[I]++;
        }
        else{
            I++;
            c[I]++;
        }
    }
    // deb(b);
    // deb(c);
    int dis=0;
    int totalBits=II*8;
    int x=totalBits/n;
    if(x>=30){
        cout<<0<<"\n";
        return 0;
    }
    int K=(1LL<<x);

    int ans=1e18;
    vi par(b.size());
    par[0]=c[0];
    for(int i=1;i<b.size();i++){
        par[i]=par[i-1]+c[i];
    }
    // deb(par);
    // deb(K);
    for(int i=0;i<b.size();i++){
        int J=min((ll)(b.size()-1),i+K-1);
        int prev=0;
        if(i!=0){
            prev=par[i-1];
        }
        int nex=0;
        nex=par[b.size()-1]-par[J];
        ans=min(ans,nex+prev);
    }
    cout<<ans<<"\n";
 
    return 0;
}