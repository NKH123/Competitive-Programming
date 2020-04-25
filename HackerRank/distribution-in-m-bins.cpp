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



int32_t main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vi a;
    REP(i,0,n){
        int A;
        cin>>A;
        a.PB(A);
    }
    sort(a.begin(),a.end());
    int M=0;
    int I=1;
    int ans=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if((i+1)%m==0){
            //deb(i+1);
            ans=(ans+(sum*I)%mod)%mod;
            //deb(ans);
            I++;
            sum=0;
        }
    }
    int rem=n%m;
    if(rem!=0){
        I--;
        sum=0;
        for(int i=(n-rem);i<n;i++){
            sum+=a[i];

        }
        //deb(sum);
        ans=(ans+(sum*I)%mod)%mod;
    }

    cout<<ans<<"\n";

    return 0;
}