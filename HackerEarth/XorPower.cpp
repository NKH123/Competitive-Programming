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
int n;
vi a;
vi X;
unordered_map<int, int>mp;
int fun(int x){
    int ans=0;
    mp.clear();
    for(int i=0;i<n;i++){
        int tmp=x^X[i];
        ans+=mp[tmp];
        if(X[i]==x){
            ans++;
        }
        mp[X[i]]++;
    }
    return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    X.resize(n);
    REP(i,0,n){
        cin>>a[i];
        X[i]=a[i];
        if(i!=0){
            X[i]=X[i]^X[i-1];
        }
    }
    int i=1;
    int ans=0;
    for(int i=1;i<=(1000000000LL);i=i*2){
        // deb(i);
        ans+=fun(i);
    }
    cout<<ans<<"\n";

	return 0;
}