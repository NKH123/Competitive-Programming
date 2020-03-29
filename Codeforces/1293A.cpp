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
    int t;
    cin>>t;
    vi a;
    set<int>S;
    while(t--){
    	int n, s, k;
    	cin>>n>>s>>k;
    	a.clear();
    	a.resize(k);
    	S.clear();
    	// REP(i,1,n+1){
    	// 	S.insert(i);
    	// }
    	REP(i,0,k){
    		cin>>a[i];
    		S.insert(a[i]);
    	}
    	int ans=1e18;
    	// for(auto g:S){
    	// 	ans=min(ans,abs(g-s));
    	// }
    	for(int i=s;i<=n;i++){
    		if(S.find(i)!=S.end()){

    		}
    		else{
    			ans=abs(i-s);
    			break;
    		}
    	}
    	for(int i=s;i>=1;i--){
    		if(S.find(i)!=S.end()){

    		}
    		else{
    			ans=min(ans,abs(i-s));
    			break;
    		}
    	}
    	cout<<ans<<"\n";

    }

    return 0;
}