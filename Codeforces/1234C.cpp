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


vector<int>a[2];
vector<int>vis[2];
void dfs(int x, int y, char next){
    vis[x][y]=1;
    if(y==0){
        return;
    }
    if(next=='U'){
        if(x==0){
            return;
        }
        else{
            if(a[0][y]==0){
                dfs(x-1,y,'U');
            }
            else{
                dfs(x-1,y,'L');
            }
        }
    }
    else if(next=='D'){
        if(x==1){
            return;
        }
        else{
            if(a[1][y]==0){
                dfs(x+1,y,'D');
            }
            else{
                dfs(x+1,y,'L');
            }
        }
    }
    else if(next=='L'){
        if(x==0){
            if(a[0][y-1]==1){
                dfs(x,y-1,'D');
            }
            else{
                dfs(x,y-1,'L');
            }
        }
        else{
            if(a[1][y-1]==1){
                dfs(x,y-1,'U');
            }
            else{
                dfs(x,y-1,'L');
            }
        }
    }
    else if(next=='R'){

    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;

    while(q--){
        int n;
        cin>>n;
        vis[1].clear();
        vis[0].clear();
        a[0].clear();
        a[1].clear();
        a[0].resize(n+1);
        a[1].resize(n+1);
        vis[0].resize(n+1);
        vis[1].resize(n+1);
        string s0, s1;
        cin>>s0;
        cin>>s1;
        for(int i=1;i<=n;i++){
            char A;
            A=s0[i-1];
            int aa=A-'0';
            if(aa>2){
                aa=1;
            }
            else{
                aa=0;
            }
            a[0][i]=aa;
        }
        for(int i=1;i<=n;i++){
            char A;
            A=s1[i-1];
            int aa=A-'0';
            if(aa>2){
                aa=1;
            }
            else{
                aa=0;
            }
            a[1][i]=aa;
        }
        char next;
        if(a[1][n]==1){
            next='U';
        }
        else{
            next='L';
        }
        dfs(1,n,next);
        if(vis[0][0]==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }




    return 0;
}