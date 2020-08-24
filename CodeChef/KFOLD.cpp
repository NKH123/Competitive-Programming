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
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int one =0, zero =0;
        for(auto g: s) {
            if(g=='1'){
                one++;
            }
            else{
                zero++;
            }
        }
        int times = n/k;
        if(one%times!=0 || zero%times!=0) {
            cout<<"IMPOSSIBLE\n";
        }
        else {
            string first = "";
            int onetimes = one/times;
            int zerotimes = zero/times;
            for(int i=0; i<zerotimes; i++){
                first = first + '0';
            }
            for(int i=0; i<onetimes; i++){
                first = first + '1';
            }
            string second = "";
            for(int i= (int)first.size() - 1; i>=0; i--) {
                second = second + first[i];
            }
            string ans ="";
            for(int i=0; i<times; i++) {
                if((i%2)==0) {
                    ans+=first;
                }
                else{
                    ans+=second;
                }
            }
            cout<<ans<<"\n";
        }
    }

    return 0;
}