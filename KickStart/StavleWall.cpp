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

vector<vector<char> >mat;
vector<char>ans;
set<int>adj[26];
int vis[26];
vector<int>ord;
int f=1;
void dfs(int I){
    vis[I]=2;

    for(auto g:adj[I]){
        if(vis[g]==1){
            dfs(g);
        }
        
    }
    ord.push_back(I);
}
void dfs1(int I){
    vis[I]=2;
    // ord.push_back();
    char Ans=I+'A';
    ans.PB(Ans);
    for(auto g:adj[I]){
        if(vis[g]==2){
            //deb("yyppypypyp");
            //deb(I);
            //deb(g);
            f=0;
        }
        else if(vis[g]==1){
            dfs1(g);
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    int T;
    cin>>t;
    T=t;
    while(t--){
        int r, c;
        cin>>r>>c;
        mat.clear();
        memset(vis,0,sizeof(vis));
        mat.resize(r,vector<char>(c));
        ord.clear();
        REP(i,0,r){
            REP(j,0,c){
                cin>>mat[i][j];
                vis[mat[i][j]-'A']=1;
            }
        }
        ans.clear();
        for(int i=0;i<26;i++){
            adj[i].clear();
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i!=(r-1)){
                    if(mat[i+1][j]!=mat[i][j]){
                        adj[mat[i+1][j]-'A'].insert(mat[i][j]-'A');
                    }
                }
            }
        }
        //deb("here");
        f=1;
        // //deb(adj);
        for(int i=0;i<26;i++){
            char A='A'+i;
            //deb(A);
            //deb(adj[i]);
        }
        // for(int i=0;i<26;i++){
        //     for(auto g:adj[i]){
        //         if(adj[g].size()==0){
        //             continue;
        //         }
        //         else if(adj[g].find(i)!=adj[g].end()){
        //             f=0;
        //         }
        //     }
        // }
        //deb(1);
        for(int i=0;i<26;i++){
            if(vis[i]==1){
                dfs(i);
            }
        }
        //deb(ord);
        memset(vis,0,sizeof(vis));
        REP(i,0,r){
            REP(j,0,c){
                    // cin>>mat[i][j];
                vis[mat[i][j]-'A']=1;
            }
        }
        for(int i=ord.size()-1;i>=0;i--){
            if(vis[ord[i]]==1)
                dfs1(ord[i]);
        }
        if(f==0){
            cout<<"Case #"<<(T-t)<<": "<<-1<<"\n";
        }
        else{



            cout<<"Case #"<<(T-t)<<": ";
            for(int i=0;i<ans.size();i++){
                cout<<ans[i];
            }
            cout<<"\n";

        }


    }

    return 0;
}