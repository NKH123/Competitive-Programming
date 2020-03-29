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
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	int l=0, r=n-1;
    	int ans=0;
    	int f=1;
    	bool vis[n];
    	memset(vis,true, sizeof(vis));
    	while(l<r){
    		if(s[l]!=s[r]){
    			// swap(s[l+1],s[l]);
    			// // swap(s[r-1],s[r]);
    			// ans++;
    			// if(s[l]!=s[r]){
    			// 	f=0;
    			// }
    			if(s[l+1]==s[r] && vis[l]&& vis[l+1]){
    				vis[l]=false;
    				vis[l+1]=false;
    				swap(s[l+1],s[l]);
    				ans++;
    			}
    			else if(s[r-1]==s[l] && vis[r] && vis[r-1]){
    				vis[r]=false;
    				vis[r-1]=false;
    				swap(s[r],s[r-1]);
    				ans++;
    			}
    			else{
    				f=0;
    			}
    		}
    		if(s[l]!=s[r]){
    			f=0;
    		}
    		if(f==0){
    			// deb(l);
    			// deb(r);
    			// deb(s);
    			break;
    		}
    		l++;
    		r--;
    	}
    	if(f==0){
    		cout<<"NO\n";
    	}
    	else{
    		cout<<"YES\n";
    		cout<<ans<<"\n";
    	}
    }

    return 0;
}