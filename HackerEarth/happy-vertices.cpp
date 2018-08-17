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
int n,m;
int x,y;
vi a[100001];
bool vt[100001];
int nodes[100001];
int count1=0;
void nd(int A){
    vt[A]=true;
    nodes[A]=0;
    for(auto g:a[A]){
            if(!vt[g])
            {
            nodes[A]++;
            nd(g);
            }
        }
    }

void dfs(int A){
    vt[A]=true;
    for(auto g:a[A]){
        if(!vt[g]){
            if(nodes[g]>nodes[A])count1++;
            dfs(g);
        }
    }
}
int main()
{   ios::sync_with_stdio(false);
    memset(vt,false,sizeof(vt));
    memset(nodes,-1,sizeof(nodes));
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        a[x].PB(y);
        a[y].PB(x);
    }
    for(int i=1; i<=n;i++){
        if(!vt[i]){
            nd(i);
        }
    }
    memset(vt,false,sizeof(vt));
    for(int i=1;i<=n;i++){
        if(!vt[i]){
            dfs(i);
        }
    }
    cout<<count1<<"\n";
    return 0;
}
