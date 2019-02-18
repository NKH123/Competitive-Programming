#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define llp 1000000007
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


int main(){
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vl aa(n);
    vl bb(n);
    //memset(aa,0,sizeof(aa));
    REP(i,0,n){
        //deb(i);

        int k;
        cin>>k;
        //deb(k);
        REP(j,0,k){
            ll aaa;
            cin>>aaa;
            //deb("before");
            //deb(aa[i]);
            bb[i]=bb[i]|(1L<<aaa);
            aa[i]=(bb[i]|bb[i]);

           // deb(aaa);
           // cout<<bitset<64>(aaa)<<"\n";
         //   deb("after");
     //       deb(aa[i]);
       //     cout<<bitset<64>(aa[i])<<"\n";
       //
        }
    }
    ll ans=(1L<<40)-1;
    //deb(ans);
    //cout<<bitset<64>(ans)<<"\n";
    REP(i,0,n){
        ans=ans&aa[i];
    }
    //deb(ans);
    //cout<<bitset<64>(ans)<<"\n";
    //deb(aa);

    cout<<__builtin_popcountll(ans)<<"\n";



	return 0;
}