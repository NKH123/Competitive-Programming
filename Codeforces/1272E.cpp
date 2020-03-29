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

int n;
vi a;
// int dp[200005];
// int vis[200005];
// vector<int>adj[200005];
vector<int>dp;
vector<int>vis;
vector<vector<int> >adj;
// int dfs(int x){
//     vis[x]=1;
//     if(dp[x]!=-1){
//         return dp[x];
//     }
//     else{
//         int ans=1e18;
//         if((x+a[x])<=n){
//             if((a[x]%2!=a[x+a[x]]%2)){
//                 ans=1;
//             }
//             else{
//                 if(vis[x+a[x]]==1 && dp[x+a[x]]==-1){
//                     ans=1e18;
//                 }
//                 else
//                     ans=min(ans,1+dfs(x+a[x]));
//             }
//         }
//         if((x-a[x])>=1){
//             if((a[x]%2!=a[x-a[x]]%2)){
//                 ans=1;
//             }
//             else if(vis[x-a[x]]==1 && dp[x-a[x]]==-1){
//                 ans=1e18;
//             }
//             else{
//                 ans=min(ans,1+dfs(x-a[x]));
//             }
//         }
//         return dp[x]=ans;
//     }
// }
queue<int>q;
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n;
    // memset(vis,0,sizeof(vis));
    dp.resize(n+1,-1);
    a.resize(n+1);
    // memset(dp,-1,sizeof(dp));
    vis.resize(n+1,0);
    adj.resize(n+1);
    REP(i,0,n+1){
        dp[i]=1e18;
    }
    REP(i,1,n+1){
        cin>>a[i];
        if(i-a[i]>=1){
            adj[i-a[i]].PB(i);
        }
        if(i+a[i]<=n){
            adj[i+a[i]].PB(i);
        }
    }
    
    REP(i,1,n+1){
        int f=0;
        if(i-a[i]>=1){
            // adj[i-a[i]].PB(i);
            if(a[i-a[i]]%2!=a[i]%2){
                dp[i]=1;
                f=1;
                q.push(i);
                vis[i]=1;
            }
        }
        if(i+a[i]<=n){
            // adj[i+a[i]].PB(i);
            if(a[i+a[i]]%2!=a[i]%2){
                dp[i]=1;
                if(f==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }   
    }
    while(q.size()!=0){
        int x=q.front();
        q.pop();
        for(auto g:adj[x]){
            if(vis[g]==1){
                continue;
            }
            else{
                dp[g]=min(dp[g],1+dp[x]);
                q.push(g);
                vis[g]=1;
            }
        }
    }

    REP(i,1,n+1){
        // if(dp[i]==-1){
        //     dfs(i);
        // }
        if(dp[i]>=1e18){
            cout<<-1<<" ";
        }
        else{
            cout<<dp[i]<<" ";
        }
    }
    cout<<"\n";


    return 0;
}