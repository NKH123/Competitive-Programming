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
    int G=0;
    int ans=1e18;
    REP(i,0,n){
        cin>>a[i];
        G=__gcd(a[i],G);
    }
    if(G!=1){
        cout<<-1<<"\n";
        return 0;
    }
    //1 case
    int ct=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            ct++;
        }
    }
    if(ct!=0){
        ans=n-ct;
        cout<<ans<<"\n";
        return 0;
    }

    for(int i=0;i<n;i++){
        // int G=a[i];
        for(int j=i;j<n;j++){
            // G=__gcd(G,a[j]);
            int G=__gcd(a[i],a[j]);
            if(G==1){
                ans=min(ans,j-i+n-1);
                break;
            }
        }
    }
    cout<<ans<<"\n";
    


    return 0;
}