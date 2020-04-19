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
#define endl "\n"
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

// #define //deb(x) cerr << #x << " = " << x << endl;

vector<vector<int> >adj;
vector<vector<int> >level;
int maxl=0;
vector<int>cnt;
vector<int>mark;
vector<int>pre;
vector<int>val;
vector<int>sum;
int dfs(int v, int p, int lev){
    int ctt=0;
    level[lev].PB(v);
    for(auto g:adj[v]){
        if(g!=p){
            ctt+=dfs(g,v,lev+1)+1;
        }
    }
    maxl=max(maxl,lev);
    val[v]=lev-(ctt);
    // cnt[v]=ctt+1;
    return ctt;
}
bool comp(int A, int B){
    return cnt[A]<cnt[B];
}
// void assign(int v, int p, int far){
//     // int expans=(far)*(cnt[v]);

//     // int Sum=0;
//     for(auto g:adj[v]){
//         if(g!=p){
//             assign(g,v,far+1);
//             Sum+=sum[g];
//         }
//     }
//     val[v]=far-cnt[v]+1;
//     // sum[v]=Sum+val[v];

// }
int32_t main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    int K=k;
    adj.clear();
    val.clear();
    val.resize(n+1);
    cnt.clear();
    sum.clear();
    sum.resize(n+1);
    cnt.resize(n+1);
    adj.resize(n+1);
    level.clear();
    level.resize(n+1);
    mark.clear();
    mark.resize(n+1);
    pre.clear();
    pre.resize(n+1);
    // //deb(1);
    for(int i=0;i<(n-1);i++){
        int A, B;
        cin>>A>>B;
        adj[A].PB(B);
        adj[B].PB(A);
    }
    REP(i,0,n+1){
        val[i]=-(1e18);
    }
    // cnt[1]=dfs(1,0);
    // //deb(2);
    dfs(1,0,0);
    
    sort(val.begin(),val.end());
    reverse(val.begin(),val.end());
    // //deb(val);
    int Ans=0;
    // //deb(K);
    for(int i=0;i<K;i++){
        Ans+=(val[i]);
        //deb(n-1-i);
        //deb(val[n-1-i]);
    }
    // //deb(7);
    cout<<Ans<<"\n";



    return 0;
}