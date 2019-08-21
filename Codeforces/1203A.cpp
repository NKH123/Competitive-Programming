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
int n;
vi a;
vi b;
bool checkRight(int ind){
	int last=0;
	for(int i=ind+1;i<2*n;i++){
		if(b[i]!=(b[i-1]+1)){
			return false;
		}
		else{
			last=b[i];
			if(last==n){
				break;
			}
		}
	}
	if(last==n){
		return true;
	}
	else{
		return false;
	}
}
bool checkLeft(int ind){
	int last=0;
	for(int i=ind-1;i>=0;i--){
		if(b[i]!=(b[i+1]+1)){
			return false;
		}
		else{
			last=b[i];
			if(last==n){
				break;
			}
		}
	}
	if(last==n){
		return true;
	}
	else{
		return false;
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		a.clear();
		b.clear();
		a.resize(n);
		b.resize(2*n);
		REP(i,0,n){
			cin>>a[i];
		}
		if(n==1){
			cout<<"YES\n";
			continue;
		}
		REP(i,0,n){
			b[i]=a[i];
		}
		for(int i=n;i<2*n;i++){
			b[i]=a[i-n];
		}
		int f=0;
		for(int i=0;i<2*n;i++){
			if(b[i]==1){
				f=f|checkRight(i);
				f=f|checkLeft(i);
			}
		}
		if(f==1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}


	return 0;
}