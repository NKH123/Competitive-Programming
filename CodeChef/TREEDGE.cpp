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

const int Max=200005;
const int N=50005;
const int LGN=22;

vector<pair<int,ll> >adj[200005];
int par[200005];
bool vt[200005];
ll pre[200005];
ll parent[22][200005],depth[Max],weight[Max], vis[Max];


int uplift(int u,int k){
	for(int i=0;i<LGN;i++){
		if(k&1)u=parent[i][u];
		k>>=1;
	}
	return u;
}
void dfs(int x,int p){
	if(x==0)par[x]=0;
	else par[x]=p;
	for(auto g:adj[x]){
		if(g.F!=p){
			dfs(g.F,x);
		}
	}
}
ll solve(int x){
	//cout<<"New call\n";
	//trace(x);
	if(pre[x]!=-1){
		return pre[x];
	}
	ll ans=0;
	for(auto g:adj[x]){
	//	trace(g.F);
		if(g.F!=par[x]){
	//		cout<<"Inside "<<x<<"\n";
	//		trace(g.F);
			ans=max(ans,g.S+solve(g.F));
		}
	}
	return pre[x]=ans;
}




void dfs1(int src){
	vis[src]=1;
	for(int i=0;i<adj[src].size();i++){
		int v=adj[src][i].first;
		int w=adj[src][i].second;
		if(vis[v])continue;
		parent[0][v]=src;
		weight[v]=weight[src]+w;
		depth[v]=depth[src]+1;
		dfs1(v);
	}
}


void init()
{
	dfs1(0);
	for(int i=1;i<22;i++){
		for(int j=0;j<N;j++){
			if(parent[i-1][j]!=-1){
				parent[i][j]=parent[i-1][parent[i-1][j]];
			}
		}
	}
}
int lca(int u,int v){
	int diff=abs(depth[u]-depth[v]);
	if(depth[u]>depth[v]){
		u=uplift(u,diff);
	}
	else if(depth[v]>depth[u]){
		v=uplift(v,diff);
	}
	if(u==v)return u;
	for(int i=22-1;i>=0;i--){
		if(parent[i][u]!=parent[i][v]){
			u=parent[i][u];
			v=parent[i][v];
		}
	}

	return parent[0][u];
}




int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
    	//memset(pre,-1,sizeof(pre));
    	int n,q;

    	cin>>n>>q;
    	for(int i=0;i<n;i++){
    		adj[i].clear();
    		pre[i]=-1;
    		weight[i]=0;
    	}
    	REP(i,0,n-1){
    		int u,v,w;
    		cin>>u>>v>>w;
    		u--;v--;
    		adj[u].PB({v,w});
    		adj[v].PB({u,w});
    	}
    	init();
    	dfs(0,-1);
    	for(int i=0;i<n;i++){
    		if(pre[i]==-1){
    			pre[i]=solve(i);
    		}
    	}
    	while(q--){
    		ll u,v,x;
    		ll ans=0;
    		cin>>u>>v>>x;
    		u--;
    		v--;
    		ll a=pre[u];
    		ll b=pre[v];
    		int lc=lca(u,v);
    		//trace(u);
    		//trace(v);
    		//trace(a);
    		//trace(b);
    		/*ans=a+b+x;
    		if(a<0){
    			if(b<0){
    				ans=x;
    			}
    			else{
    				ans=b+x;
    			}
    		}
    		if(b<0){
    			if(a<0){
    				ans=x;
    			}
    			else{
    				ans=a+x;
    			}
    		}*/
    		ll a1=x;
    		ll a2=x+b;
    		ll a3=a+x;
    		ll a4=a+b+x;
    		ll a5=weight[u]+weight[v]-2*weight[lc];
    		ans=max(a1,max(a2,max(a3,max(a4,a5))));
    		//trace(a5);
    		cout<<ans<<"\n";
    	}
    }
    return 0;
}	