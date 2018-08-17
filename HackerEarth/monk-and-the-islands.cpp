#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int t;
int n,m,x,y;
vi a[10001];
vi dist(10001);
vector<bool> visited(10001);
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        dist.clear();
        visited.clear();
        cin>>n>>m;
        dist.resize(n+1);
        visited.resize(n+1);
        fill(visited.begin(), visited.end(), false);
        while(m--){
            cin>>x>>y;
            a[x].PB(y);
            a[y].PB(x);
        }
        dist[1]=0;
        queue<int> s;
        s.push(1);
        visited[1]=true;
        while(!s.empty()){
            int g=s.front();
            s.pop();
            for(auto G:a[g]){
                if(visited[G]==false){
                visited[G]=true;
                dist[G]=dist[g]+1;
                s.push(G);
                }
            }
        }
        cout<<dist[n]<<"\n";
    }
    return 0;
}
