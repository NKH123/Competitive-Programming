#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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

vi adj[300005];
vi red;
vi blu;
bool vis[300005];
vi a;
ll ans=0;

void dfs(int v){
    vis[v]=1;
    for(auto g:adj[v]){
        if(!vis[g]){
            dfs(g);
            red[v]+=red[g];
            blu[v]+=blu[g];
        }
    }
    if(a[v]==1){
        red[v]++;
    }
    if(a[v]==2){
        blu[v]++;
    }

}
void dfs1(int v){
    vis[v]=1;
    for(auto g:adj[v]){
        if(!vis[g]){
            dfs1(g);
            /*if((!(red[g]>0 && blu[g]>0) &&((red[1]-red[g])>0) && ((blu[1]-blu[g])>0))){
                ans++;

            }*/
       
            int f=1;
            if(red[g]>0 && blu[g]>0){
                f=0;
            }
            if((red[1]-red[g])>0 &&(blu[1]-blu[g])>0){
                f=0;
            }
            if(f)ans++;
        }
    }
    /*if(a[i]==1){
        red[v]++;
    }
    if(a[i]==2){
        blu[v]++;
    }*/

}




int main(){
	ios::sync_with_stdio(false);
    int n;
    memset(vis,false,sizeof(vis));
    //memset(red,0,sizeof(red));
    //memset(blu,0,sizeof(blu));
    cin>>n;
    a.resize(n+1);
    red.resize(n+1);
    blu.resize(n+1);
    REP(i,1,n+1){
        cin>>a[i];
    }

    REP(i,0,n-1){
        int A,B;
        cin>>A>>B;
        adj[A].PB(B);
        adj[B].PB(A);
    }
    dfs(1);
     memset(vis,false,sizeof(vis));
    dfs1(1);
   
    cout<<ans<<"\n";

    return 0;
}