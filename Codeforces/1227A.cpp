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
    vector<pair<int, int> >seg;
    while(t--){
    	int n;
    	cin>>n;
    	seg.clear();
    	int L, R;

    	for(int i=0;i<n;i++){
    		int A, B;
    		cin>>A>>B;
    		seg.PB({A,B});
    		if(i==0){
    			L=seg[0].S;
    			R=seg[0].F;
    		}
    		else{
    			L=min(L,seg[i].S);
    			R=max(R,seg[i].F);
    		}
    	}
    	// sort(seg.begin(),seg.end());
    	// int A=seg[0].S;
    	// int B=seg[n-1].F;
    	// if((n-1)==0){
    	// 	cout<<0<<"\n";
    	// 	continue;
    	// }
    	// deb(R);
    	// deb(L);
    	cout<<max((R-L),0LL)<<"\n";

    }

    return 0;
}