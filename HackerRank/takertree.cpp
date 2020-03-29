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
vector<vector<int> >adj;
int ind;
int dis;
void dfs(int x, int p, int D){
    // int ind=x;

    // int dis=0;
    if(D>dis){
        dis=D;
        ind=x;
    }
    for(auto g:adj[x]){
        if(g!=p){
            dfs(g,x,D+1);

        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    // while(t--){
    int n;
    for(int i=1;i<=100;i++){
        // cin>>n;
        n=i;
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<=n;i++){
            int A=i;
            int B=i&(i-1);
            if(A!=B){
                adj[A].PB(B);
                adj[B].PB(A);
            }
        }
        //find diameter
        ind=0;
        dis=0;
        dfs(0,-1,0);
        dis=0;
        dfs(ind,-1,0);
        deb(n);
        n++;
        cout<<dis<<"\n";
        int ans;
        if(n!=1)
        ans=floor(log2(n)) + floor(log2(2*n/3));
        else{
            ans=floor(log2(n))+1;
        }
        deb(ans);
        if(ans==dis){
            deb("yes");
        }
        else{
            deb("no");
            return 0;
        }
    }
    // }



    return 0;
}