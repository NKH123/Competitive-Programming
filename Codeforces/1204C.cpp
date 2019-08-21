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


char adj[105][105];
int dis[105][105];
int32_t main(){
    ios::sync_with_stdio(false);
    // memset(adj,0,sizeof(adj));
    int n;  
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dis[i+1][j+1]=1e18;
            cin>>adj[i+1][j+1];
            if(adj[i+1][j+1]=='1'){
                dis[i+1][j+1]=1;
            }
        }
    }
    
    int m;
    cin>>m;
    vi p(m);
    REP(i,0,m){
        cin>>p[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    vector<int>ans;
    ans.PB(p[0]);
    int I=0;
    for(int i=1;i<(m-1);i++){
        if(p[I]==p[i+1]){
            ans.PB(p[i]);
            I=i;
            continue;
        }
        if(dis[p[I]][p[i+1]]<(dis[p[I]][p[i]]+dis[p[i]][p[i+1]])){
            // if(p[i]!=ans[ans.size()-1]) 
            ans.PB(p[i]);
            I=i;
            // else{
            //     ans.PB(p[i-1]);
            //     ans.PB(p[i]);
            // }

        }
        else{

        }
        
    }
    ans.PB(p[m-1]);
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    return 0;
}