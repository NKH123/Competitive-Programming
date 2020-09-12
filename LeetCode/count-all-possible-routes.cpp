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
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // int dp[locations.size() + 5][fuel + 5];
        vector<vector<int> > dp(locations.size(),vector<int>(fuel+1,0));
        // memset(dp,0,sizeof(dp));
        dp[start][fuel]=1;
        for(int i=fuel; i>=0; i--) {
        	for(int j=0; j<locations.size(); j++) {
        		for(int k=0; k<locations.size(); k++) {
        			if(j!=k && abs(locations[j]-locations[k]) <=i) {
        				int dist= abs(locations[j]-locations[k]);
        				dp[k][i-dist]+=dp[j][i];
        			}
        		}
        	}
        }
        int ans = 0;
        int modd= (1e9);
        modd+=7;
        deb(dp);
        for(int i=0; i<=fuel; i++) {
        	ans = (ans + dp[finish][i])%modd;
        }
        return ans;
    }
};


int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n) {
    	cin>>a[i];
    }
    int st, en, f;
    cin>>st>>en>>f;
    Solution S;
    cout<<S.countRoutes(a,st,en, f)<<"\n";

    return 0;
}