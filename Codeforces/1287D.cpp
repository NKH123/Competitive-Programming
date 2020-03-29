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

int n;
vi p,c;
vector<int>adj[2500];
vector<int>dfs(int x){
    // deb(x);
    vector<int>ret;
    for(auto g:adj[x]){
        vector<int>x=dfs(g);
        for(auto h:x){
            ret.PB(h);
        }

    }
    if(c[x]>ret.size()){
        cout<<"NO\n";
        // return 0;
        // goto here;
        exit(0);
    }
    ret.insert(ret.begin()+c[x],x);
    return ret;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n;
    p.resize(n);
    c.resize(n);
    int root;
    REP(i,0,n){
        cin>>p[i]>>c[i];
        if(p[i]!=0){
            adj[p[i]-1].PB(i);
        }
        else{
            root=i;
        }
    }
    // deb("here");
    vector<int>order=dfs(root);
    // deb(order);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        ans[order[i]]=i+1;
    }
    cout<<"YES\n";
    REP(i,0,n){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    // label here:
    return 0;
}