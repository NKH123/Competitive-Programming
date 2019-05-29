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
vi a;
int n;

bool check(int sz, int st){
    for(int i=1;sz-2*i>=st;i++){
        if(a[sz]==a[sz-i] && a[sz-i]==a[sz-2*i]){
            return false;
        }
    }
    return true;

}
int32_t main(){
	ios::sync_with_stdio(false);
    string s;
    cin>>s;
    a.resize(s.size());
    REP(i,0,s.size()){
        if(s[i]=='0'){
            a[i]=0;
        }
        else{
            a[i]=1;
        }
    }
    int ans=0;
        n=s.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<min(n,i+9);j++){
            if(!check(j,i)){
                ans+=(n-1)-(j)+1;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}