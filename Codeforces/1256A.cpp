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



int32_t main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
    	int a, b, n, S;
    	cin>>a>>b>>n>>S;
    	int f=0;
    	// for(int x=0;;x++){
    	// 	if(x*n>S){
    	// 		break;
    	// 	}
    	// 	else{
    	// 		int rem=S-x*n;
    	// 		if(rem<=b){
    	// 			f=1;
    	// 			break;
    	// 		}
    	// 	}
    	// }
    	// int up=S;
    	// int low=S-b;
    	// int up1=up/n;
    	// int low1=low/n;
    	// // if(up%n!=0){
    	// // 	up1++;
    	// // }
    	// if(low%n!=0){
    	// 	low1++;
    	// }
    	// if(a<=up1 && a>=low1){
    	// 	f=1;
    	// }
    	int l=0, r=a;
    	while(l<=r){
    		int mid=(l+r)/2;
    		int rem=S-mid*n;
    		if(rem<0){
    			r=mid-1;
    		}
    		else{
    			if(rem<=b){
    				f=1;
    				break;
    			}
    			else{
    				l=mid+1;
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