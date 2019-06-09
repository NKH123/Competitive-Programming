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
map<int, int>M;
int fun(int x){
    // deb(x);
    if(M.count(x)!=0){
        return M[x];
    }
    if(x==1){
        M[x]=0;
        return 0;
    }
    int ans=1e18;
    if(x%2==0){
        ans=min(ans,1+fun(x/2));
    }
    if(x%3==0){
        ans=min(ans,1+fun(2*x/3));

    }
    if(x%5==0){
        ans=min(ans,1+fun(4*x/5));
    }
    return M[x]=ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int ans=fun(n);
        if(ans==1e18){
            ans=-1;
        }
        cout<<ans<<"\n";
    }



	return 0;
}