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
int a[1002][1002];
bool vt[1002][1002];
int n, m;
int maxi;
int troop;
void travel(int A, int b){
    queue<pair<int,int> >q=queue<pair<int,int> >();
    q.push({A,b});
    int size=1;
    vt[A][b]=true;
    while(!q.empty()){
        auto P=q.front();
        q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0&&j==0)continue;
                if(vt[P.F+i][P.S+j]==false && a[P.F+i][P.S+j]==1){
                        vt[P.F+i][P.S+j]=true;
                        size++;
                        q.push({P.F+i,P.S+j});
                }
            }
        }
    }
    maxi=max(maxi,size);
}
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        maxi=0;
        troop=0;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(vt,false,sizeof(vt));
        for(int i=1; i<=n;i++){
            for(int j=1; j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m;j++){
                if(a[i][j]==1 && vt[i][j]==false){
                    troop++;
                    travel(i,j);
                }
            }
        }
        cout<<troop<<" "<<maxi<<"\n";
        }
    return 0;
}
