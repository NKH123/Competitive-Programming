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


int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    vi red;

    REP(i,0,n){
        cin>>a[i];

    }
    int st=0;
    // int ans=0;
    red.resize(1);
    red[0]=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            red[red.size()-1]++;
        }
        else{
            red.PB(1);
        }
    }
    // deb(red);
    int ans=0;
    for(int i=0;i<red.size()-1;i++){
        ans=max(ans,min(red[i],red[i+1]));
    }
    cout<<(2*ans)<<"\n";
    // for(int i=0;i<n;i++){
    //     if(t[i]==1){
    //         st++;
    //     }
    //     else{
    //         st--;
    //     }
    //     if(st==0){

    //     }
    // }



	return 0;
}
