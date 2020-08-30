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
// #define 0 0LL
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

int min(int A, int B){
    // return min(A, B);
    if (A> B) {
        return B;
    }
    else {
        return A;
    }
}
int max(int A, int B) {
    if (A< B) {
        return B;
    }
    else {
        return A;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int small_cap, large_cap;
        cin>>small_cap>>large_cap;
        int small_no, large_no;
        cin>>small_no>>large_no;
        int small_weight, large_weight;
        cin>>small_weight>>large_weight;
        if(small_cap>large_cap) {
            swap(small_cap,large_cap);
        }
        if(small_weight>large_weight) {
            swap(small_weight,large_weight);
            swap(small_no, large_no);
        }
        deb(small_cap);
        deb(large_cap);
        deb(small_no);
        deb(large_no);
        deb(small_weight);
        deb(large_weight);
        deb("**********\n\n");
        int ans = 0;
        int cantake = small_cap/small_weight;
        int took = (min(small_no, cantake));
        ans += took;
        small_cap = max(0,small_cap - small_weight*took );
        small_no -= min(cantake, small_no);
        deb(ans);
        deb(small_cap);
        deb(took);
        deb(small_no);
        
        deb("**********\n\n");
        cantake = small_cap/large_weight;
        took = min(large_no, cantake);
        ans +=(took);
        small_cap = max(0, small_cap - large_weight*took);
        large_no -= min(large_no, cantake);
        deb(ans);
        deb(small_cap);
        deb(took);
        deb(large_no);
        
        deb("**********\n\n");
        cantake = large_cap/small_weight;
        took = min(small_no, cantake);
        ans +=(took);
        large_cap = max(0, large_cap - small_weight*took);
        small_no -= min(small_no, cantake);
        deb(ans);
        deb(large_cap);
        deb(took);
        deb(small_no);
        
        deb("**********\n\n");
        cantake = large_cap/large_weight;
        took = min(large_no, cantake);
        ans +=(took);
        large_cap = max(0, large_cap - large_weight*took);
        large_no -= min(large_no, cantake);
        deb(ans);
        deb(large_cap);
        deb(took);
        deb(large_no);


        deb("**********\n\n");


        // large gets filled
        cout<<ans<<"\n";
    }

    return 0;
}