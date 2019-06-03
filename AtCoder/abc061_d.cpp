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
vector<pair<pair<int, int>,int> >edge;
vector<int>d;
int32_t main(){
	ios::sync_with_stdio(false);
    int n, m;
    cin>>n;cin>>m;
    d.resize(n+1);
    REP(i,0,n+1){
        d[i]=1e18;
    }
    REP(i,0,m){
        int a, b, c;
        cin>>a>>b>>c;
        edge.PB({{a,b},-1*c});
    }
    d[1]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[edge[j].F.F]<1e18){
                d[edge[j].F.S]=min(d[edge[j].F.S],d[edge[j].F.F]+edge[j].S);
            }
        }
    }
    int now=d[n];
    for(int j=0;j<m;j++){
        if(d[edge[j].F.F]<1e18){
            d[edge[j].F.S]=min(d[edge[j].F.S],d[edge[j].F.F]+edge[j].S);
        }
    }
    int after=d[n];
    if(after!=now){
        cout<<"inf"<<"\n";
    }
    else{
        cout<<(-d[n])<<"\n";
    }
    return 0;
}