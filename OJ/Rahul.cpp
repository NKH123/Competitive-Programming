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
template < typename T >
ostream &operator << ( ostream & os, const queue< T > &v ) {
    os << "[";
    typename queue< T > :: const_iterator it;
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
int n, m;
vector<vector<pair<int, int> > >adj;
void print(queue<int>q){
	cout<<"[ ";
	while(q.size()!=0){
		int v=q.front();
		cout<<v<<", ";
		q.pop();
	}
	cout<<" ]\n";
}
vector<int>dis;
vector<set<int> >S;
vector<int>vis;
map<pair<int, int> , int>M;
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    adj.clear();
    //////deb(1);
    adj.resize(n+1);
    for(int i=0;i<m;i++){
    	int A, B, C;
    	cin>>A>>B>>C;
    	adj[A].PB({B,C});
    	adj[B].PB({A,C});
    }
    //////deb(2);
    dis.clear();
    dis.resize(n+1,1e18);
    if(dis[1]!=(1e18)){
    	return 0;
    }
    S.clear();
    S.resize(n+1);
    //////deb("yo");
    dis[1]=0;
    queue<int>q;
    q.push(1);
    vis.clear();
    vis.resize(n+1,0);
    //////deb(3);
    while(q.size()!=0){
    	// ////deb(q);

    	int v=q.front();
    	//deb(v);
    	// print(q);
    	q.pop();
    	vis[v]=1;
    	//one more idea distance specific to the line
    	for(auto g:adj[v]){
    		int prev=dis[g.first];
    		int f=0;
    		if(S[v].find(g.second)!=S[v].end()){
    			dis[g.first]=min(dis[g.first],dis[v]);
    			
    		}
    		else{
    			dis[g.first]=min(dis[g.first],dis[v]+1);
    			
    		}
    		if(prev>dis[g.first] ||((M[{v,g.first}]!=1)&&prev==(dis[g.first]))&&(S[g.first].find(g.second)==S[g.first].end())){
    			q.push(g.first);
    			M[{v,g.first}]=1;
    			M[{g.first,v}]=1;
    			S[g.first].insert(g.second);
    		}
    		
    	}
    	//////deb(v);
    	// print(q);
    	//deb(dis);
    	//deb("*********************");
    }
    ////deb(dis);
    if(dis[n]==(1e18)){
    	cout<<-1<<"\n";
    }
    else{
    	cout<<dis[n]<<"\n";
    }

    return 0;
}