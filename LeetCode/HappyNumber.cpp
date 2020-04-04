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
    int no_digits(int n){
        int ans=0;
        while(n>0){
            n=n/10;
            ans++;
        }
        return ans;
    }
    int process(int n){
        int ans=0;
        while(n>0){
            int N=n%10;
            deb(n);
            deb(N);
            ans=ans+N*N;
            n=n/10;
            // ans++;
        }
        return ans;
    }
    bool isHappy(int n) {
        int iter=0;
        while(no_digits(n)>1){
                n=process(n);
                iter++;
            cout<<n<<"\n";
                    
            // if(iter>100000){
            //     break;
            // }
        }
        return n==1;
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    Solution S;
    // cout<<S.isHappy(19)<<"\n";
    deb(S.process(19));

    return 0;
}