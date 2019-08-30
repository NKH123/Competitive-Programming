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
    vi rem;
    while(q--){
        int n, m;
        cin>>n>>m;
        if(m>n){
            cout<<0<<"\n";
            continue;
        }
        rem.clear();
        rem.PB((m%10));
        int put=(rem[0]+(m%10))%10;
        int sum=(m%10);
        while(put!=rem[0]){
            rem.PB(put);
            sum+=put;
            put=(put+(m%10))%10;
        }
        // deb(m);
        // deb(rem);
        int ans=0;
        int no=(n/(rem.size()*(m)));
        // deb(no);
        // deb(sum);
        ans=no*sum;
        int Rem=((n/m)%(rem.size()));
        // deb(Rem);
        for(int i=0;i<Rem;i++){
            ans+=rem[i];
        }
        cout<<ans<<"\n";
    }



    return 0;
}