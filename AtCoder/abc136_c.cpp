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
    vi h(n);
    REP(i,0,n){
        cin>>h[i];
    }
    vi maxi(n);
    vi mini(n);
    maxi[0]=h[0];
    for(int i=1;i<n;i++){
        maxi[i]=max(h[i],maxi[i-1]);
    }
    mini[n-1]=h[n-1];
    for(int i=n-2;i>=0;i--){
        mini[i]=min(h[i],mini[i+1]);
    }
    // deb(maxi);
    // deb(mini);
    int f=1;
    for(int i=0;i<(n-1);i++){
        if((maxi[i]-mini[i+1])>1){
            f=0;
        }
    }
    if(f==1){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }



    return 0;
}