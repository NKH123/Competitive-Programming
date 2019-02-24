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

list<int> adj[100005]; 
int main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,0,2*n){
        int A;
        cin>>A;
        adj[A].PB(i+1);
        if(adj[A].size()==2){
            if(adj[A].front()>adj[A].back()){
                swap(adj[A].front(),adj[A].back());
            }
        }
    }
    ll ans=adj[1].front()+adj[1].back()-1-1;
    int cur1=adj[1].front();
    int cur2=adj[1].back();
    //deb(ans);
    for(int i=2;i<=n;i++){
        /*if(abs(adj[i].front()-cur)<abs(adj[i].back()-cur)){

            ans+=abs(adj[i].front()-cur);
            cur=adj[i].front();
            adj[i].pop_front();
        }
        else{
          ans+=abs(adj[i].back()-cur);
          cur=adj[i].back();
          adj[i].pop_back();

      }*/
        //deb(i);
        ll ssum=0;
    
        ssum+=abs(adj[i].front()-cur1)+abs(adj[i].back()-cur2);
        ll ssum1=0;
        ssum1+=abs(adj[i].front()-cur2)+abs(adj[i].back()-cur1);
        /*deb(cur1);
        deb(cur2);
        deb(ssum);
        deb(ssum1);*/
        if(ssum<ssum1){
            ans+=ssum;
            cur1=adj[i].front();
            cur2=adj[i].back();
        }
        else{
            ans+=ssum1;
            cur2=adj[i].front();
            cur1=adj[i].back();
        }



  }
  /*cur=1;
  for(int i=1;i<=n;i++){
    ans+=abs(adj[i].front()-cur);
    cur=adj[i].front();
}*/
cout<<ans<<"\n";



return 0;
}