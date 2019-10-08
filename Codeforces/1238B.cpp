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
    vi a;
    while(q--){
        int n, r;
        cin>>n>>r;
        a.clear();
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vi b;
        b.clear();
        b.PB(a[0]);
        for(int i=0;i<n;i++){
            if(b[b.size()-1]!=a[i]){
                b.PB(a[i]);
            }
        }
        int S=b.size();
        int cur=0;
        for(int i=S-1;i>=0;i--){
            int gap=r*cur;
            int X=b[i]-gap;
            if(X<=0){
                break;
            }
            else{
                cur++;
            }
        }
        cout<<cur<<"\n";
    }


    return 0;
}