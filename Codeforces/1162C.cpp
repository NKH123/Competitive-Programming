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

set<int>adj[100005];
int32_t main(){
	ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    vi a(n+1,0);
    vi c;
    set<int>ss;
    REP(i,0,k){
        int A;
        cin>>A;
        c.PB(A);
        a[A]=1;
        adj[A].insert(i);
        ss.insert(A);
    }

    int ans=3*(n-2)+2*2;
    ans-=ss.size();
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            if(i==1){
                auto poss=adj[i+1].upper_bound(*(adj[i].begin()));
                if(poss!=adj[i+1].end()){
                    ans--;
                }
            }
            else if(i==(n)){
                auto poss=adj[i-1].upper_bound(*(adj[i].begin()));
                if(poss!=adj[i-1].end()){
                    ans--;
                }
            }
            else{
               auto poss=adj[i+1].upper_bound(*(adj[i].begin()));
                if(poss!=adj[i+1].end()){
                    ans--;
                }
              poss=adj[i-1].upper_bound(*(adj[i].begin()));
                if(poss!=adj[i-1].end()){
                    ans--;
                }
            }
        }
    }
    cout<<ans<<"\n";



    return 0;
}