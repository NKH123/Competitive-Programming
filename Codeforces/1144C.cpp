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

bool comp(int a, int b){
    return a>b;
}
int32_t main(){
	ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n)cin>>a[i];
    vi b(200005,-1);
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(b[a[i]]==-1){
            b[a[i]]=1;
        }
        else {
            if(b[a[i]]==1){
                b[a[i]]=2;
            }
            else{
                cout<<"NO\n";
                return 0;
            }
        }
    }

    cout<<"YES\n";
    vi inc;
    vi dec;
    vi mark(200005,0);
    REP(i,0,n){
        if(mark[a[i]])continue;
        if(b[a[i]]==1){
            inc.PB(a[i]);
        }
        else{
            inc.PB(a[i]);
            dec.PB(a[i]);
        }
        mark[a[i]]=1;
    }
    sort(inc.begin(),inc.end());
    sort(dec.begin(),dec.end(),comp);
    cout<<inc.size()<<"\n";
    for(auto g:inc){
        cout<<g<<" ";
    }
    cout<<"\n";
    cout<<dec.size()<<"\n";
    for(auto g:dec){
        cout<<g<<" ";
    }
    cout<<"\n";

    return 0;
}