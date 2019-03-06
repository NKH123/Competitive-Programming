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
vector<vector<int> >adj;
vector<vector<int> >ans;
vector<vector<int>> c;

void matmul(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int n=a.size();
    //vector<vector<int>> c(n, vector<int>(n));
    c.clear();
    c.resize(n);
    REP(i,0,n){
        c[i].resize(n);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
               // c[i][j]=add(c[i][j], mul(a[i][k], b[k][j]));
                c[i][j]=(c[i][j]%mod+(((a[i][k]%mod)*b[k][j]%mod)%mod))%mod;
            }
        }
    }
   // return c;
}
void matmul1()
{
    int n=adj.size();
    //vector<vector<int>> c(n, vector<int>(n));
    c.clear();
    c.resize(n);
    REP(i,0,n){
        c[i].resize(n);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
               // c[i][j]=add(c[i][j], mul(a[i][k], b[k][j]));
                c[i][j]=(c[i][j]%mod+(((ans[i][k]%mod)*adj[k][j]%mod)%mod))%mod;
            }
        }
    }
   // return c;
}
void matmul2()
{
    int n=adj.size();
    //vector<vector<int>> c(n, vector<int>(n));
    c.clear();
    c.resize(n);
    REP(i,0,n){
        c[i].resize(n);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
               // c[i][j]=add(c[i][j], mul(a[i][k], b[k][j]));
                c[i][j]=(c[i][j]%mod+(((adj[i][k]%mod)*adj[k][j]%mod)%mod))%mod;
            }
        }
    }
   // return c;
}


void power(ll k){
    int n=adj.size();
    //vector<vector<int>> res(n, vector<int>(n));
    for(int i=0; i<n; i++) ans[i][i]=1;

    while(k>0) {
        if(k&1) {
            matmul1();
            REP(i,0,n){
                REP(j,0,n){
                    ans[i][j]=c[i][j];
                }
            }
        }
        matmul2();
        REP(i,0,n){
                REP(j,0,n){
                    adj[i][j]=c[i][j];
                }
            }
        k>>=1;
    }
    //return res;
}

int32_t main(){
	ios::sync_with_stdio(false);
    ll n, q, k, m;
    cin>>n>>q>>k>>m;
    adj.resize(n);
    REP(i,0,n){
        adj[i].resize(n);
    }
    ans.resize(n);
    REP(i,0,n){
        ans[i].resize(n);
    }
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u][v]=1;
    }
    power(k);
    while(q--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        //assert(u>=0 and u<n and v>=0 and v<n);
        cout<<adj[u][v]<<"\n";
    }




	return 0;
}