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

vector<pair<int, int> > adj[50005];
vi d;
void dijkstra(int s){
    d[s]=0;
    set<pair<int, int> >q;
    q.insert({0,s});
    while(!q.empty()){
        int v=q.begin()->second;
        q.erase(q.begin());
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                // p[to] = v;
                q.insert({d[to], to});
            }
        }

    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    while(t--){
        int n;
        cin>>n;
        d.resize(n+1);
        REP(i,0,n+1){
            d[i]=1e18;
        }
        if(n==1){
            cout<<0<<"\n";
            continue;
        }
        REP(i,0,50005){
            adj[i].clear();
        }
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
            adj[i+1].PB({a[i],0});
        }
        for(int i=0;i<n;i++){
            if(i==0){
                adj[i+1].PB({i+2,1});
            }
            else if (i==n-1){
                adj[i+1].PB({i,1});
            }
            else{
                adj[i+1].PB({i+2,1});
                adj[i+1].PB({i,1});
            }
        }
        dijkstra(1);
        cout<<d[n]<<"\n";

    }



	return 0;
}