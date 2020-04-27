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
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        int two=min(2*a,b);
        int one=a;
        int ans=0;
        if(x>y){
            swap(x,y);
        }
        if(x<0 && y<0){
            ans=(abs(x-y)*one);
            ans+=(two*(abs(y)));
            // ans+=(b);
        }
        else if(x<0 && y==0){
            ans=(abs(x))*one;
            // ans+=b;
        }
        else if(x<0 && y>0){
            //1
            ans=one*(abs(x)+abs(y));
            // ans+=b;


            //-1
        }
        else if(x==0 && y==0){
            ans=0;
        }
        else if(x==0 && y>0){
            ans=one*(y);
            // ans+=(b);

        }
        else if(x>0 && y>0){
            ans+=(one*(abs(x-y)));
            ans+=(two*(x));
            // ans+=b;
        }
        cout<<ans<<"\n";

    }

    return 0;
}