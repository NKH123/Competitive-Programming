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
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
#define llp 1000000007
#define mod 1000000007
set<int> adj[100005];
vi a;
vi b;
bool v1[100005];
bool v2[100005];
void dfs(int v,int p){
	a.PB(v);
	v1[v]=true;
	for(auto g:adj[v]){
		if(g!=p && v1[g]!=true){
			dfs(g,v);
		}
	}

	
}

void bfs(int v){
	v2[v]=true;
	b.PB(v);
	queue<int>q;
	q.push(v);
	while(!q.empty()){
		int s = q.front(); q.pop();
// process node s
		for (auto u : adj[s]) {
			if (v2[u]) continue;
			v2[u] = true;
			//distance[u] = distance[s]+1;
			b.PB(u);
			q.push(u);
		}
	}
}
	int main()
	{   ios::sync_with_stdio(false);
		memset(v1,false,sizeof(v1));
		memset(v2,false,sizeof(v2));
		int n,m;
		cin>>n>>m;
		REP(i,0,m){
			int A,B;
			cin>>A>>B;
			if(A!=B){
				adj[A].insert(B);
				adj[B].insert(A);
			}
		}
		dfs(1,0);
		bfs(1);
		int f=0;
		//print(a);
		//print(b);
		for(int i=0;i<n;i++){
			if(a[i]>b[i]){
				f=1;
				break;
			}
			else if(a[i]<b[i]){
				f=0;break;
			}
		}//trace(f);
		if(f){
			for(auto g:b){
				cout<<g<<" ";
			}
			cout<<"\n";
		}
		else{
			for(auto g:a){
				cout<<g<<" ";
			}
			cout<<"\n";
		}
		return 0;
	}