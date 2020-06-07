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
vi a;
vi T;
int build(int v, int l, int r){
	if(l>r)return 0;
	if(l==r){
		if(a[l]%5==0){
			T[v]=1;
		}
		else{
			T[v]=0;
		}
		return T[v];
	}
	else{
		int mid=(l+r)/2;
		T[v]=build(v*2,l,mid)+build(v*2+1,mid+1,r);
		return T[v];
	}
}
int query(int v, int sl, int sr, int l, int r){
	if(sl>sr){
		return 0;
	}
	else if(sl>r || sr<l){
		return 0;
	}
	else if(sl>=l && sr<=r){
		return T[v];
	}
	else{
		int smid=(sl+sr)/2;
		int ans=query(2*v,sl,smid,l,min(r,smid))+query(2*v+1,smid+1,sr,max(smid+1,l),r);
		return ans;
	}
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	int n, q;
    	cin>>n>>q;
    	a.clear();
    	a.resize(n);
    	REP(i,0,n){
    		cin>>a[i];
    	}
    	T.clear();
    	T.resize(4*n+5);
    	build(1,0,n-1);
    	// deb(T);
    	while(q--){
    		int l, r;
    		cin>>l>>r;
    		l--, r--;
    		int ans=query(1,0,n-1,l,r);
    		cout<<ans<<"\n";
    	}
    }

    return 0;
}