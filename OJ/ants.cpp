#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
#define forn(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
// typedef long long ll;
// #define int ll
// typedef vector<int> vi;
// typedef vector<long long> vl;
// typedef pair<int,int> pi;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define sz(x) (int)(x.size())
#define mod 1000000007
#define endl "\n"
#define all(c) (c).begin(),(c).end()
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
    ll n,m;
    ll t;
    //string s;
    //ll ans = 0;
    // scanf("%lld %lld %lld\n", &n, &m,&t);
    cin>>n>>m>>t;
    ll s;
    char c;
    vpi reord;
    vll ord(n);
    ll total_speed = 0;
    vll outpos;
    forn(i,0,n) {
        //deb(i);
        // scanf("%lld %c\n", &s, &c);
        cin>>s>>c;
        reord.pb(mp(s%m,i));
        if(c=='1'){
            c='R';
        }
        else{
            c='L';
        }
        if(c=='R') {
            total_speed++;
            outpos.pb((s + t)%m);
        }
        else {
            total_speed--;
            outpos.pb((s+m-(t%m))%m);
        }
    }
    sort(all(reord));
    sort(all(outpos));
    ll totshift = 0;
    forn(i,0,n) {
        totshift+=outpos[i]+2*m - reord[i].first;
    }
    //totshift = totshift % (n*m);
    //ll actualshift = ((total_speed * (t%(m*n))) %(m*n) + m*n)%(m*n);
    ll tmod = t%(m*n);
    ll A = total_speed/10000;
    ll B= total_speed%10000;
    ll actualshift = (((A*tmod)%(m*n) * (10000))%(m*n) + (B*tmod)%(m*n))%(m*n);
    ll diff= ((totshift-actualshift)/m)%n;
    vi ans(n);
    forn(i,0,n) {
        ans[reord[i].second] = outpos[(i+n-diff)%n];
        if(ans[reord[i].second]==0)         ans[reord[i].second]=m;
    }
    forn(i,0,n){
        int Ans=ans[i]%m;
        cout<<Ans<<"\n";
    } 

    return 0;
}