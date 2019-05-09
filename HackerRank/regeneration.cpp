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
int a[6][1005][1005];
int t[6][1005][1005];
int n, m;
int X[4]{0,1,0,-1};
int Y[4]{1,0,-1,0};
int x[6],y[6];
queue<pair<int, int > > q;
void bfs(int xx, int yy, int N){
    // deb("yooooooooooo");
    // deb(N);
    q.push({xx,yy});
    t[N][xx][yy]=0;
    a[N][xx][yy]=1;
    while(!q.empty()){
        auto G=q.front();
        q.pop();
        // deb(G);
        for(int i=0;i<4;i++){
            int j=i;
            int f=0;
            for(int k=0;k<6;k++){
                if(G.F+X[i]==x[k] && G.S+Y[i]==y[k] ){
                    f=1;
                    break;
                }
            }
            if(f){
                continue;
            }
                     //if(i==0 && j==0)continue;
            if(G.F+X[i] >=n || G.F+X[i] <0)continue;
            else if(G.S+Y[j] >=m || G.S+Y[j] <0)continue;
            else if(a[N][G.F+X[i]][G.S+Y[j]]==0){
                a[N][G.F+X[i]][G.S+Y[j]]=1;
                q.push({G.F+X[i],G.S+Y[i]});
                //Count[G.F+X[i]][G.S+Y[j]]=Count[G.F][G.S]+1;
                //ct =max(ct,Count[G.F+X[i]][G.S+Y[j]]);
                t[N][G.F+X[i]][G.S+Y[j]]=t[N][G.F][G.S]+N+1;
            }
        }
    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    cin>>n>>m;
    //memset(t,0,sizeof(t));
    for(int i=0;i<6;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
               // cout<<t[i][j][k]<<" ";
                t[i][j][k]=1e18;
            }
            // cout<<"\n";
        }
        // cout<<"\n";
    }

    memset(a,0,sizeof(a));
    REP(i,0,6){
        cin>>x[i]>>y[i];
        x[i]--;
        y[i]--;
    }
    for(int i=0;i<6;i++){
        bfs(x[i],y[i],i);
    }

    for(int i=0;i<6;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cout<<t[i][j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ans=0;
            for(int k=0;k<6;k++){
                if(t[k][i][j]<t[ans][i][j]){
                    ans=k;
                }
            }
            // deb(ans);
            char aa='A'+ans;
            cout<<aa;
        }
        cout<<"\n";

    }



    return 0;
}