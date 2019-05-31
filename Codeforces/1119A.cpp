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
    vi c(n);
    REP(i,0,n)cin>>c[i];
    vi las(n+1);
    REP(i,0,n){
        las[c[i]]=i;
    }
    int f=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        if(i==0){
            f++;
            for(int j=0;j<n;j++){
                if(c[i]!=c[j]){
                    ans=max(ans,las[c[j]]-i);
                }
            }
        }
        else{
            if(c[i]!=c[0]){
                f++;
                for(int j=0;j<n;j++){
                    if(c[i]!=c[j]){
                        ans=max(ans,las[c[j]]-i);
                    }
                }
            }
        }
        if(f==2){
            break;
        }
    }
    cout<<ans<<"\n";


    return 0;
}