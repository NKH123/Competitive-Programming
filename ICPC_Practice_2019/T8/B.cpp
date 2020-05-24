#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
//vector <int> 
// push_back
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
ll max(ll a, ll b){
    if(a>=b)
        return a;

    return b; 
}

ll getlargest(ll x2){
    ll maxp = 0;
    ll cp = x2;
    if(x2%2==0){
        maxp = 2;
        while(x2%2==0){
            x2/=2;
        }
    }

    for(ll i=3;i*i<=x2;i++){
        if(x2%i==0){
            maxp = i;

            while(x2%i==0){
                x2/=i;
            }
        }
    }

    if(x2!=1){
        maxp = x2;
    }

    
    // if(maxp == cp)
    //     return 1;


    return maxp;


}

int main(){

    ll x2;

    cin>>x2;
    ll cp = x2;

    vector <ll> p2;
    ll maxp = 0;

    if(x2%2==0){
        maxp = 2;
        while(x2%2==0){
            x2/=2;
        }
    }

    for(ll i=3;i*i<=x2;i++){
        if(x2%i==0){
            maxp = i;
            while(x2%i==0){
                x2/=i;
            }
        }
    }

    if(x2!=1){
        maxp = x2;
    }

    

    ll start = cp - maxp+1;
    ll mini = 1e18;
    // deb(maxp);
    // deb(cp);
    for(ll i=start; i<=cp; i++){
        int L=getlargest(i);
        if(L!=i){
            // deb(i);
            // deb(L);
            // deb(i-L+1);
            mini = min(mini, i-L+1);
        }
    }

    cout<<mini<<endl;

    return 0;
}

