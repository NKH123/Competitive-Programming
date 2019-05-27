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

map<pair<int, int>,bool >M;
int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int T=t;
	while(t--){
		M.clear();
		int n, r, c, sr, sc;
		cin>>n>>r>>c>>sr>>sc;
		string mvs;
		cin>>mvs;
		M[{sr,sc}]=true;
		int R=sr, C=sc;
		REP(i,0,mvs.size()){
			// deb(i);
			if(mvs[i]=='N'){
				if(M.count({R-1,C})==0){
					R--;
					M[{R,C}]=true;
				}
				else{
					int f=0;
					while(M.count({R-1,C})){
						R--;
						if(R==1){
							f=1;
							break;
						}
					}
					if(f==0){
						R--;
						M[{R,C}]=true;
					}
				}
			}
			if(mvs[i]=='S'){
				if(M.count({R+1,C})==0){
					R++;
					M[{R,C}]=true;
				}
				else{
					int f=0;
					while(M.count({R+1,C})){
						R++;
						if(R==r){
							f=1;
							break;
						}
					}
					if(f==0){
						R++;
						M[{R,C}]=true;
					}
				}

			}
			if(mvs[i]=='E'){
				if(M.count({R,C+1})==0){
					C++;
					M[{R,C}]=true;
				}
				else{
					int f=0;
					while(M.count({R,C+1})){
						C++;
						if(C==c){
							f=1;
							break;
						}
					}
					if(f==0){
						C++;
						M[{R,C}]=true;
					}
				}

			}
			if(mvs[i]=='W'){
				if(M.count({R,C-1})==0){
					C--;
					M[{R,C}]=true;
				}
				else{
					int f=0;
					while(M.count({R,C-1})){
						C--;
						if(C==1){
							f=1;
							break;
						}
					}
					if(f==0){
						C--;
						M[{R,C}]=true;
					}
				}
			}
			// cout<<R<<" "<<C<<"\n";
		}
		cout<<"Case #"<<T-t<<": "<<R<<" "<<C<<"\n";

	}



	return 0;
}