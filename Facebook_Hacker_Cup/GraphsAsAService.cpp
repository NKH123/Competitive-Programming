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


set<pair<int, pair<int, int> > >M;
vector<vector< pair<int, int > > >adj;
vector<int>dis;
void dijkstra(int s){
    dis[s]=0;
    set<pair<int, int> >q;
    q.insert({0,s});
    while(!q.empty()){
        int v=q.begin()->S;
        q.erase(q.begin());
        for(auto E:adj[v]){
            int to=E.F;
            int len=E.S;
            if(dis[v]+len<dis[to]){
                q.erase({dis[to],to});
                dis[to]=dis[v]+len;
                q.insert({dis[to],to});
            }
        }
    }

}



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    while(t--){
        int n, m;
        cin>>n>>m;
        adj.clear();
        dis.clear();
        adj.resize(n+1);
        M.clear();
        for(int i=0;i<m;i++){
            int X, Y, Z;
            cin>>X>>Y>>Z;
            M.insert({Z,{X,Y}});
        }
        int f=1;
        for(auto g:M){
            int X, Y, Z;
            Z=g.F;
            X=g.S.F;
            Y=g.S.S;
            dis.assign(n+1,1e18);
            dijkstra(X);
            if(dis[Y]< Z){
                f=0;
                break;
            }
            else if(dis[Y]>Z){
                adj[X].PB({Y,Z});
                adj[Y].PB({X,Z});
            }

        }
        cout<<"Case #"<<T-t<<": ";
        if(f==0){

            cout<<"Impossible\n";
            continue;
        }
        else{
            set< pair< pair<int, int>, int > >Edj;
            Edj.clear();
            for(int i=1;i<=n;i++){
                for(int j=0;j<adj[i].size();j++){
                    if(adj[i][j].F>i){
                        Edj.insert({{i,adj[i][j].F},adj[i][j].S});
                    }
                }
            }
            cout<<Edj.size()<<"\n";
            for(auto g:Edj){
                cout<<g.F.F<<" "<<g.F.S<<" "<<g.S<<"\n";
            }
        }

    }
    return 0;
}