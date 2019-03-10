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

vector<pair<int,int> >pts;
vi K;
vi val;
int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		pts.clear();
		//pts.resize(n);.clear
		K.clear();
		REP(i,0,n){
			int A,B;
			cin>>A>>B;
			pts.PB({A,B});
		}
		REP(i,0,n){
			int A;
			cin>>A;
			K.PB(A);
		}

		//deb(pts);
		//deb(K);
		int ans=0;
		val.clear();
		val.resize(n);
		sort(K.begin(),K.end());
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				//ans+=K[i]*(abs(pts[i].F-pts[j].F)+abs(pts[j].S-pts[i].S));
				val[i]+=abs(pts[i].F-pts[j].F)+abs(pts[j].S-pts[i].S);
			}
		}
		sort(val.begin(),val.end());
		for(int i=0;i<n;i++){
			ans+=K[i]*val[i];
		}
		cout<<ans<<"\n";

	}



	return 0;
}