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

list<int> pos[100005]; 
int main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,0,2*n){
        int A;
        cin>>A;
        pos[A].PB(i+1);
        if(pos[A].size()==2){
            if(pos[A].front()>pos[A].back()){
                swap(pos[A].front(),pos[A].back());
            }
        }
    }
    ll ans=pos[1].front()+pos[1].back();
    REP(i,2,n+1){
        ans+=abs(pos[i].front()-pos[i-1].front())+abs(pos[i].back()-pos[i-1].back());
    }
    cout<<ans<<"\n";
    /*ll ans=0;
    int cur=1;
    for(int i=1;i<=n;i++){
        if(abs(adj[i].front()-cur)<abs(adj[i].back()-cur)){

            ans+=abs(adj[i].front()-cur);
            cur=adj[i].front();
            adj[i].pop_front();
        }
        else{
          ans+=abs(adj[i].back()-cur);
          cur=adj[i].back();
          adj[i].pop_back();

      }
  }
  cur=1;
  for(int i=1;i<=n;i++){
    ans+=abs(adj[i].front()-cur);
    cur=adj[i].front();
}
cout<<ans<<"\n";*/



return 0;
}