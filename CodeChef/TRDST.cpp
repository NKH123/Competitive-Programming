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
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
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

vi adj[100005];
vi dis;
vi Dis;
vi vis;
vi K;
vi D;
int n;
void solve(int ind){
   queue<int>q=queue<int>();
   //deb(ind);
   q.push(ind);
   dis[0]++;
   Dis[ind]=0;
   vis[ind]=1;
  // deb(adj[ind]);
   while(!q.empty()){
    int a=q.front();
    q.pop();
   // deb(a);
    for(auto g:adj[a]){
       // deb(g);
        //deb(adj[a]);
        if(vis[g]==1)continue;
        vis[g]=1;
        Dis[g]=Dis[a]+1;
        dis[Dis[g]]++;
        q.push(g);
        

        
        
    }
   // deb(q.size());
}
//deb("I'm here\n");
//cout<<"Dis befor: ans source is "<<ind<<"\n";
//deb(dis);
for(int i=n-2;i>=0;i--){
    dis[i]=dis[i]+dis[i+1];
}
//deb("I'm here2\n");
int l=0,r=n-1;
ll ans=0;
//cout<<"Dis after cum sum\n";
//deb(Dis);
//deb(dis);
//deb(K);
//int ct=0;
//deb(K[ind]);
while(l<=r){
    //deb(K);
    //deb(dis);
    //deb(K[ind]);
    //deb(ind);
    //deb(l);deb(r);

    int mid=(l+r)/2;
    //deb(mid);
    if(dis[mid]==K[ind]){
        ans=mid;
        l=mid+1;
    }
    else if(dis[mid]>K[ind]){
       l=mid+1;
   }
   else if(dis[mid]<K[ind]){
    //deb("I'm here");
    ans=mid;
    r=mid-1;
}
}
//deb("I'm here3\n");
int mid=ans;
if(dis[mid]!=K[ind])ans--;
//deb(mid);
ans--;
//deb(ans);
D[ind]=ans;
}






int main(){
	ios::sync_with_stdio(false);

    cin>>n;
    K.resize(n);
    REP(i,0,n)cin>>K[i];
    dis.resize(n);
    Dis.resize(n);
    vis.resize(n);
    D.resize(n);
    REP(i,0,n-1){
        int A,B;
        cin>>A>>B;
        A--;
        B--;
        adj[A].PB(B);
        adj[B].PB(A);
    }
    REP(i,0,n){
        dis.clear();
        dis.resize(n);
        Dis.clear();
        Dis.resize(n);
        vis.clear();
        vis.resize(n);
        solve(i);
    }
  //  solve(4);
    REP(i,0,n)cout<<D[i]<<" ";
    cout<<"\n";
    return 0;
}