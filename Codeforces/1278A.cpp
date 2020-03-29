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
vi a(26,0);
vi b(26,0);
bool check(){
	REP(i,0,26){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}
int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		string s, h;
		cin>>s>>h;

		a.clear();
		a.resize(26);

		b.clear();
		b.resize(26);
		for(int i=0;i<s.size();i++){
			a[s[i]-'a']++;
		}
    	// for(int i=0;i<h.size();i++){
    	// 	b[h[i]-'a']++;
    	// }
    	// int f=1;
    	// for(auto g:s){
    	// 	if(b[g-'a']<a[g-'a']){
    	// 		f=0;
    	// 		break;
    	// 	}
    	// }
		int f=0;
		int l=0, r=s.size()-1;
		if(h.size()<s.size()){
			cout<<"NO\n";
			continue;
		}
		else{
			for(int i=0;i<s.size();i++){
				b[h[i]-'a']++;
			}
			if(check()){
					f=1;
					
				}
			while(r<h.size()){
				r++;
				l++;
				b[h[l-1]-'a']--;
				if(r==h.size()){
					break;
				}
				b[h[r]-'a']++;
				if(check()){
					f=1;
					break;
				}
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