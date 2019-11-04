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

int dp[100005][3];
vector<vector<int> >adj;
int col[100005];
map<int, int>Order;
map<int, int>revOrder;
int Ct=0;
void dfs(int x, int p){
    ++Ct;
    Order[Ct]=x;
    // revOrder[x]=Ct;
    for(auto g:adj[x]){
        if(g!=p){
            dfs(g,x);
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi c1(n);
    vi c2(n);
    vi c3(n);
    REP(i,0,n){
        cin>>c1[i];
    }
    REP(i,0,n){
        cin>>c2[i];
    }
    REP(i,0,n){
        cin>>c3[i];
    }
    adj.resize(n+1);
    for(int i=0;i<(n-1);i++){
        int U, V;
        cin>>U>>V;
        adj[U].PB(V);
        adj[V].PB(U);
    }
    int f=1;
    for(int i=1;i<=n;i++){
        if(adj[i].size()>2){
            f=0;
        }
    }
    if(f==0){
        cout<<-1<<"\n";
    }
    else{
        int root=0;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==1){
                root=i;
                break;
            }
        }
        dfs(root,0);
        memset(col,0,sizeof(col));
        vector<int>perm;
        perm.PB(1);
        perm.PB(2);
        perm.PB(3);
        int Cost=1e18;
        vector<int>Correct;
        do{
            int temp=0;
            for(int i=1;i<=n;i++){
                int cur=Order[i]-1;
                int D=i%3;
                if(D==0){
                    if(perm[2]==1)
                        temp+=c1[cur];
                    if(perm[2]==2)
                        temp+=c2[cur];
                    if(perm[2]==3)
                        temp+=c3[cur];
                }
                else if(D==1){
                    if(perm[0]==1)
                        temp+=c1[cur];
                    if(perm[0]==2)
                        temp+=c2[cur];
                    if(perm[0]==3)
                        temp+=c3[cur];
                }
                else{
                    if(perm[1]==1)
                        temp+=c1[cur];
                    if(perm[1]==2)
                        temp+=c2[cur];
                    if(perm[1]==3)
                        temp+=c3[cur];
                }

            }
            if(temp<Cost){
                Cost=temp;
                Correct=perm;
            }
        }while(next_permutation(perm.begin(),perm.end()));

        cout<<Cost<<"\n";
        for(int i=1;i<=n;i++){
            int cur=Order[i];
            int D=i%3;
            if(D==0){
                D=2;
            }
            else if(D==1){
                D=0;
            }
            else if(D==2){
                D=1;
            }
            if(Correct[D]==1){
                col[cur]=1;
            }
            else if(Correct[D]==2){
                col[cur]=2;
            }
            else{
                col[cur]=3;
            }

        }
        for(int i=1;i<=n;i++){
            cout<<col[i]<<" ";
        }
        cout<<"\n";


        
    }
    return 0;
}