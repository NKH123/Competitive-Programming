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
vector<int>ans(7);
vector<char> Ans(7);
int A;
vector<vector<char> > aa;

char get(int i){
	if(i==0){
		return 'R';
	}
	else if(i==1){
		return 'P';
	}
	else if(i==2){
		return 'S';
	}
}
bool wwin(char x, char y){
	if(x==y){
		return true;
	}
	else if(x=='R'){
		if(y=='P'){
			return false;
		}
		else if(y=='S'){
			return true;            
		}
	}
	else if(x=='P'){
		if(y=='R'){
			return true;
		}
		else if(y=='S'){
			return false;            
		}
	}
	else if(x=='S'){
		if(y=='R'){
			return false;
		}
		else if(y=='P'){
			return true;            
		}

	}
}
bool Win(int i){
	int n=min(Ans.size(),aa[i].size());
	// deb(n);
	// deb(i);
	// deb(aa[i]);
	for(int j=0;j<n;j++){
		if(wwin(Ans[j],aa[i][j])){
			if(Ans[j]!=aa[i][j]){
				return true;
			}
		}
		else{
			// deb("loss");
			return false;
		}
	}
	int f=0;
	for(int j=0;j<n;j++){
		if(Ans[j]!=aa[i][j]){
			f=1;
			break;
		}
	}
	if(f){
		// deb("win");
		return true;
	}
	else{
		// deb("draw");
		return false;
	}    
}
bool win(){
	// deb(ans);
	for(int i=0;i<7;i++){
		Ans[i]=get(ans[i]);
	}
	// deb(Ans);
	for(int i=0;i<A;i++ ){
		if(Win(i)){

		}
		else{
			return false;
		}
	}
	return true;
}

int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int T=t;
	while(t--){

		cin>>A;
		aa.clear();

		aa.resize(A);
		REP(i,0,A){
			string s;
			cin>>s;
			for(int j=0;j<s.size();j++){
				aa[i].push_back(s[j]);
			}
		}
		int f=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					for(int l=0;l<3;l++){
						for(int m=0;m<3;m++){
							for(int n=0;n<3;n++){
								for(int o=0;o<3;o++){
									ans.clear();
									ans.push_back(i);
									ans.push_back(j);
									ans.push_back(k);
									ans.push_back(l);
									ans.push_back(m);
									ans.push_back(n);
									ans.push_back(o);
									if(win()){

										f=1;
										o=3;
										n=3;
										m=3;
										l=3;
										k=3;
										j=3;
										i=3;
										break;
									}
								}
							}

						}
					}
				}
			}
		}
		cout<<"Case #"<<T-t<<": ";
		if(f){
			REP(i,0,7){
				cout<<Ans[i];
			}
			cout<<"\n";
		}
		else{
			cout<<"IMPOSSIBLE\n";
		}

	}



	return 0;
}