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

int a[15][15];
int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int r, c;
		cin>>r>>c;
		memset(a,0,sizeof(a));
		REP(i,0,r){
			REP(j,0,c){
				cin>>a[i][j];
			}
		}
		int f=1;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(i==0){
					if(j==0){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
					else if(j==(c-1)){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
					else if(a[i][j]>=3){
						f=0;
						break;
					}
				}
				else if(j==0){
					if(i==0){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
					else if(i==(r-1)){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
					else if(a[i][j]>=3){
						f=0;
						break;
					}
				}
				else if(i==(r-1)){
					if(j==0){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
					else if(j==(c-1)){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
					else if(a[i][j]>=3){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
				}
				else if(j==(c-1)){
					if(i==0){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
					else if(i==(r-1)){
						if(a[i][j]>=2){
							f=0;
							break;
						}
					}
					else if(a[i][j]>=3){
						f=0;
						break;
					}
				}
				else if(a[i][j]>=4){
					f=0;
					break;
				}
			}
		}
		if(f==1){
			cout<<"Stable\n";
		}
		else{
			cout<<"Unstable\n";
		}
	}



	return 0;
}