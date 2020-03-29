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

int mask=0;
vector<int>adj[100005];
int temp=0;
int ans=0;
vector<int>b;
vector<int>take;
void dfs(int x, int p){
    if(take[x]==1){
        temp+=b[x];
    }
    for(auto g:adj[x]){
        if(g!=p){
            dfs(g,x);
        }
    }

}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    while(t--){
        ans=0;
        int n;
        cin>>n;
        take.clear();
        take.resize(n);
        b.clear();
        b.resize(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<=n;i++){
            adj[i].clear();
        }
        for(int i=0;i<(n-1);i++){
            int A, B;
            cin>>A>>B;
            A--;
            B--;
            adj[A].PB(B);
            adj[B].PB(A);
        }
        for(int i=0;i<(1LL<<n);i++){
            mask=i;
            temp=0;
            take.clear();
            take.resize(n,0);
            for(int j=0;j<n;j++){
                if((mask&(1LL<<j))!=0){
                    take[j]=1;
                    for(auto g:adj[j]){
                        take[g]=1;
                    }
                }
            }

            dfs(0,0);
            ans=max(ans,temp);
        }
        cout<<"Case #"<<(T-t)<<": "<<ans<<"\n";

    }



    return 0;
}