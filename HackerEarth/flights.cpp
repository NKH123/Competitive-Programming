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
    int n;
    cin>>n;
    vector<vector<int> >adj(n,vector<int>(n));
    vector<vector<int> >dis(n,vector<int>(n));
    //int adj[n+5][n+5];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
            dis[i][j]=adj[i][j];
        }
    }
    REP(i,0,4){
        deb(adj[i]);
    }
    //int dis[n+5][n+5];
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                deb(i);
                deb(j);
                deb(k);
                if(dis[i][j]>max(adj[i][k],adj[k][j])){
                    dis[i][j]=max(adj[i][k],adj[k][i]);
                    deb("change");
                    deb(dis[i][j]);
                }
                deb("for now");
                deb(dis[i][j]);
            }
        }
    }
    int ans=(1e18);
    deb("yo");
    REP(i,0,4){
        deb(adj[i]);
    }
    deb("yo yo");
    REP(i,0,4){
        deb(dis[i]);
    }
    //deb(adj);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
               ans=min(adj[i][j],ans);
        }
    }
    cout<<ans<<"\n";



	return 0;
}