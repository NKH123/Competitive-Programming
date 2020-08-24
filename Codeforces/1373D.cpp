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
vi arr;
int maximumEvenIndexSum () {
    vector<vector<int> > dp(arr.size(), vector<int>(2,0));  //dp[i][0] stores the sum ending at ith position towards the left such that left_index to i length is even, dp[i][1] stores odd length subarray  
    int maximum_sum = 0;
    for ( int  i = 0; i < arr.size(); i+=2) {
        maximum_sum += arr[i];  
        arr[i] = -arr[i];
    }
    int add_after_swap = 0;
    dp[0][1] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        dp[i][0] = max(dp[i][0], arr[i] + dp[i - 1][1]);
        dp[i][1] = max(arr[i], arr[i] + dp[i - 1][0]);
        add_after_swap = max(add_after_swap, dp[i][0]);
    }
    maximum_sum += add_after_swap;
    // deb(arr);
    // deb(dp);
    // deb(add_after_swap);
    return maximum_sum;
}


int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        arr.resize(n);
        REP(i,0,n){
            cin>>arr[i];
        }
        cout<<maximumEvenIndexSum()<<"\n";
    }

    return 0;
}