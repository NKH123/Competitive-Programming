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
string s;
bool fun(int ind){
	int ct=1;
	for(int i=ind+1;i<s.size();i++){
		if(s[i]=='0'){
			s[i]='1';
			break;
		}
		else{
			s[i]='0';
			ct++;
		}
	}
	if((ct%2)==0){
		return false;
	}
	else{
		return true;
	}
}


int32_t main(){
    ios::sync_with_stdio(false);
    int t;
	cin>>t;
	while(t--){
		cin>>s;
		int ct=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				ct++;
			}
		}
		if((ct%2)!=0){
			cout<<"WIN\n";
		}
		else{
			cout<<"LOSE\n";
		}
	}
	return 0;

}
