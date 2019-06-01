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


int32_t main(){
	ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    int ta, tb;
    cin>>ta>>tb;
    int k;
    cin>>k;
    vi a(n);
    REP(i,0,n)cin>>a[i];
    vi b(m);
    REP(i,0,m)cin>>b[i];
    b.PB(1e18);
    int ans=-1;
    int time=-1;
    // deb(a);
    // deb(b);
    // deb(ta);
    // deb(tb);
    // deb(k);
    if(k>=n){
        cout<<-1<<"\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        if(i>k)continue;
        int temp=i;
        // deb(i);
        auto g=lower_bound(b.begin(),b.end(),a[i]+ta)-b.begin();
        // deb(g);
        int remmoves=k-temp;
        g=min((int)b.size()-1,g+remmoves);
        int ttime=b[g]+tb;
        // deb(g);
        // deb(ttime);
        if(time<ttime){
            time=ttime;
        }
    }
    if(time==((1e18)+tb)){
        time=-1;
    }
    cout<<time<<"\n";



	return 0;
}