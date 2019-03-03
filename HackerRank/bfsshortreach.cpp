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

vector<int>adj[100005];
vector<int>dist;
vector<int>ans;
int main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<100005;i++){
        adj[i].clear();
    }
    int n;
    cin>>n;
    //deb(n);
    int m;
    cin>>m;
   // deb(m);
    REP(i,0,m){
        int A,B;
        cin>>A>>B;
        adj[A-1].PB(B-1);
        adj[B-1].PB(A-1);
    }
    int s;
    cin>>s;
    //deb(s);

    dist.clear();
    dist.resize(n);
    for(int i=0;i<n;i++){
        dist[i]=-1;
    }
    queue<int>q=queue<int>();
    q.push(s-1);
    dist[s-1]=0;
    while(!q.empty()){
        int gg=q.front();
        
        q.pop();
        for(auto ggg:adj[gg]){
            if(dist[ggg]==-1){
                dist[ggg]=dist[gg]+1;
                q.push(ggg);
            }
        }
    }    
    ans.clear();
    for(int i=0;i<n;i++){
        if(i!=(s-1)){
            if(dist[i]!=-1)
            ans.push_back(dist[i]*6);
            else{
            ans.push_back(dist[i]);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";


   //deb(ans);
}
	return 0;
}