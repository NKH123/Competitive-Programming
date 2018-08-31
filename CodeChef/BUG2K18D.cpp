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
int a[12][12][12];
int main()
{   ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        //memset(a,0,sizeof(a));
        int l,h,b;
        cin>>l>>h>>b;
        int pre[12][12][12];
        memset(a,0,sizeof(a));
        memset(pre,0,sizeof(pre));
        for(int k=1;k<=h;k++){
            for(int j=1; j<=b;j++){
                for(int i=1; i<=l;i++){
                    cin>>a[i][j][k];
                    pre[i][j][k]=a[i][j][k];
                }
            }
        }
        for(int i=1;i<=l;i++){
            for(int j=1; j<=b;j++){
                for(int k=1;k<=h;k++){
                    pre[i][j][k]+=pre[i][j][k-1];
                }
            }
        }
         for(int i=1;i<=l;i++){
            for(int k=1; k<=h;k++){
                for(int j=1;j<=b;j++){
                    pre[i][j][k]+=pre[i][j-1][k];
                }
            }
        }
         for(int j=1;j<=b;j++){
            for(int k=1; k<=h;k++){
                for(int i=1;i<=l;i++){
                    pre[i][j][k]+=pre[i-1][j][k];
                }
            }
        }

        long long wmax=-(1e13);
        ll pmax=-(1e13);
        ll w,p;

    for(int i=1;i<=l;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=h;k++){
                for(int x=i;x<=l;x++){
                    for(int y=j;y<=b;y++){
                        for(int z=k;z<=h;z++){
                            w=pre[x][y][z]-pre[i-1][y][z]-pre[x][j-1][z]-pre[x][y][k-1]+pre[i-1][j-1][z]+pre[i-1][y][k-1]+pre[x][j-1][k-1]-pre[i-1][j-1][k-1];
                            wmax=max(wmax,w);
                            p=w*(x-i+1)*(y-j+1)*(z-k+1);
                            pmax=max(pmax,p);
                        }
                    }
                }
            }
        }
    }
    cout<<wmax<<" "<<pmax<<"\n";

    }
    return 0;
}
