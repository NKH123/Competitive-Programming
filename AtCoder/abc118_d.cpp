#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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
vi a={0,2,5,5,4,5,6,3,7,6};
int n, m;
vi A;
vi ans;
int dp[11000];
int fun(int N){
	if(N<0){
		return -1;
	}
	if(dp[N]!=-1){
		return dp[N];
	}
	if(N==0){
		return dp[N]=0;
	}
	else{
		int dig=-1;
		for(int i=0;i<A.size();i++){
			int temp=fun(N-a[A[i]]);
			if(temp==-1)continue;
			if(temp>dig){
				dig=temp;
			}
		}
		if(dig==-1){
			return dp[N]=-1;
		}
		else{
			return dp[N]=1+dig;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	A.resize(m);
	REP(i,0,m){
		cin>>A[i];
	}
	sort(A.begin(),A.end());
	fun(n);
	int I=n;
    while(I>0){
    	int ind=-1;
    	for(int i=0;i<A.size();i++){
    		if(I<a[A[i]])continue;
    		if(dp[I-a[A[i]]]==(dp[I]-1)){
    			ind=i;
    		}
    	}
    	ans.PB(A[ind]);
    	I-=a[A[ind]];
    }
    REP(i,0,ans.size()){
    	cout<<ans[i];
    }
    cout<<"\n";

	return 0;
}


