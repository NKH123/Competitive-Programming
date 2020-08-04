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

#define deb(x) cerr << #x << " = " << x << endl;

int n, m, a, b, c, d;
vector<vector<int> >A;
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};
vector<vector<bool> >vis;
// void dfs(int x, int y, int P){
//     vis[x][y]=true;
//     for(int i=0;i<4;i++){
//             int X=x+ dx[i];
//             int Y=y + dy[i];
//             if(X>=0 && X<n && Y>=0 && Y<m){
//                 if(!vis[X][Y] && abs(A[x][y]-A[X][Y])<=P){
//                     dfs(X, Y, P);
//                 }
//             }
//         }
// }
bool can(int P){
    vis.clear();
    vis.resize(n, vector<bool>(m,false));
    vis[a][b]=true;
    queue<pair<int, int> >q;
    q.push({a,b});
    while(q.size()!=0){
        auto cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int X=cur.F + dx[i];
            int Y=cur.S + dy[i];
            if(X>=0 && X<n && Y>=0 && Y<m){
                if(!vis[X][Y] && abs(A[cur.F][cur.S]-A[X][Y])<=P){
                    vis[X][Y] =  true;
                    q.push({X, Y});
                }
            }
        }
    }
    // dfs(a, b, P);
    return vis[c][d];
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>a>>b>>c>>d;
    A.resize(n, vector<int>(m));
    REP(i,0,n){
        REP(j,0,m){
            cin>>A[i][j];
        }
    }
    a--;
    b--;
    c--;
    d--;
    assert(a>=0 && a<n);
    assert(c>=0 && c<n);
    assert(b>=0 && b<m);
    assert(d>=0 && d<m);
    int l = 0, r= 1e9;
    int ans = 1e18;
    while(l<=r){
        int mid = (l + r)/2;
        if(can(mid)){
            r=mid-1;
            ans = mid;
        }
        else{
            l = mid +1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}