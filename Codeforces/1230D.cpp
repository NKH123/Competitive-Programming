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
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    map<int, int>M;
    REP(i,0,n){
        cin>>a[i];
        M[a[i]]++;
    }
    int sum=0;
    REP(i,0,n){
        cin>>b[i];
        sum+=b[i];
    }
    int ans=0;
    set<int>many;
    for(int i=0;i<n;i++){
        if(M[a[i]]>1){
            ans+=b[i];
            many.insert(a[i]);
        }
    }
    if(many.size()!=0)
    for(int i=0;i<n;i++){
        if(M[a[i]]>1)continue;
        int f=0;
        for(auto g:many){
            int ff=1;
            for(int j=0;j<62;j++){
                if(((1LL<<j)&(a[i]))!=0 && ((1LL<<j)&(g))==0){
                    ff=0;
                }
            }
            if(ff==1){
                f=1;
            }

        }

        if(f==1){
            ans+=b[i];
        }
    }
    cout<<ans<<"\n";

 
 
 
 
    return 0;
}
