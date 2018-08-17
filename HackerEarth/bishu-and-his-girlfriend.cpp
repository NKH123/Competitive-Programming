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
int n;
int u,v;
int q,x;
vector<int>a[1001];
bool gf[1001];
bool vt[1001];
int dist[1001];
int main()
{   ios::sync_with_stdio(false);
    memset(gf,false,sizeof(gf));
    memset(vt,false,sizeof(vt));
    cin>>n;
    REP(i,1,n){
        cin>>u>>v;
        a[u].PB(v);
        a[v].PB(u);
    }
    cin>>q;
    while(q--){
        cin>>x;
        gf[x]=true;
    }
    x=0;
    int xd=10000;
    int xn=10000;
    queue<int> Q;
    Q.push(1);
    dist[1]=0;
    vt[1]=true;
    while(!Q.empty()){
        int G=Q.front();
        Q.pop();
        for(auto g:a[G]){
            if(vt[g])continue;
            vt[g]=true;
            dist[g]=dist[G]+1;
            Q.push(g);
            if(gf[g]){
                if(dist[g]<=xd){
                    if(g<xn){
                        x=g;
                        xd=dist[g];
                        xn=g;
                        }
                }
            }
        }
    }
    cout<<x<<"\n";
    return 0;
}
