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


int power(int x, int y){
	if(y==0){
		return 1LL;
	}
	else{
		int ans = power(x, y/2);
		ans= (ans*ans)%mod;
		if(y%2==1){
			ans=(ans*x)%mod;
		}
		return ans;
	}
}
int MAX = 1000005;
int cnt[1000005];

void pre(){
	for(int i = 2;i<MAX;i++){
		if(cnt[i]!=0){
			continue;
		}
		else{
			for(int j = i;j<MAX;j+=i){
				cnt[j]++;
			}
		}
	}
}
int32_t main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    memset(cnt, 0, sizeof(cnt));
    pre();
    // for(int i=0;i<100;i++){
    // 	cout<<"{"<<i<<", "<<cnt[i]<<"}, ";
    // }
    cout<<"\n";
    while(q--){
    	int a, b;
    	cin>>a>>b;
    	int B=b;
    	int y = 0;
    	y = cnt[b];
    	int z = power(y, mod-2);
    	int x =cnt[a];
    	int A =a;
    	int ans = (x*z)%mod;
    	cout<<ans<<"\n";

    }

    return 0;
}