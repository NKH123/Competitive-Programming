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

int power(int a, int b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a%mod;
	}
	if(b%2==1){
		int A=power(a,b/2);
		A=(A*A)%mod;
		A=(a*A)%mod;
		return A;
	}
	else{
		int A=power(a,b/2);
		A=(A*A)%mod;
		// A=(a*A)%mod;
		return A;
	}
}
int h,w,a,b;
int fact[200005];
int ways(int f1,int f2, int t1, int t2){
	int num=fact[t1-f1+t2-f2];
	int den=(power(fact[t1-f1],mod-2)*power(fact[t2-f2],mod-2))%mod;
	int ans=(num*den)%mod;
	return ans;
}
int32_t main(){
	ios::sync_with_stdio(false);
	
	cin>>h>>w>>a>>b;
	// cout<<fun(h,w)<<"\n";
	fact[0]=1;
	for(int i=1;i<200005;i++){
		fact[i]=(i*fact[i-1])%mod;
	}
	int ans=0;
	 // deb(ways(1,1,1,1));
	for(int i=b+1;i<=w;i++){
		// deb(i);
		ans=(ans+(ways(1,1,h-a,i)*ways(h-a+1,i,h,w))%mod)%mod;
	}
	cout<<ans<<"\n";



	return 0;
}