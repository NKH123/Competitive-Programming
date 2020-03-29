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
    int n, sx, sy;
    cin>>n>>sx>>sy;
    // vi x, y;
    vector<pair<int, int> >xy;
    int up=0, down=0, left=0, right=0;
    REP(i,0,n){
        int A, B;
        cin>>A>>B;
        int X=A, Y=B;
        xy.PB({A,B});
        if(Y>=(sy+1)){
            up++;
        }
        if(Y<=(sy-1)){
            down++;
        }
        if(X>=(sx+1)){
            right++;
        }
        if(X<=(sx-1)){
            left++;
        }

    }
    int ans=max({up,down,right,left});
    cout<<max({up,down,right,left})<<"\n";
    if(up==ans){
        cout<<sx<<" "<<(sy+1)<<"\n";
    }
    else if(down==ans){
        cout<<sx<<" "<<(sy-1)<<"\n";
    }
    else if(left==ans){
        cout<<(sx-1)<<" "<<(sy)<<"\n";
    }
    else if(right==ans){
        cout<<(sx+1)<<" "<<(sy)<<"\n";
    }


    return 0;
}