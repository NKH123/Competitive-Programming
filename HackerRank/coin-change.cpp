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
vi c;
long long f[255][55];
long long solve(int N, int M){
    if(M<=0 || N<0){
        return 0;
    }
    if(N==0){
        return 1ll;
    }
    //int p1, p2;
    if(f[N][M-1]==-1){
        f[N][M-1]=solve(N,M-1);
    }

    if((N-c[m-M])>=0){
    if(f[N-c[m-M]][M]==-1){
      f[N-c[m-M]][M]=solve(N-c[m-M],M);
    }

    return f[N][M]=f[N][M-1]+f[N-c[m-M]][M];
    }
    else{
        return f[N][M]=f[N][M-1];
    }

}



int main()
{   ios::sync_with_stdio(false);
    cin>>n>>m;
    memset(f,-1,sizeof(f));
/*REP(i,0,255){
    REP(j,0,55)
{
        cout<<f[i][j]<<" ";
    }
    cout<<"\n";
}*/
    c.resize(m);
    REP(i,0,m){
        cin>>c[i];
    }
    
    sort(c.begin(),c.end());
    
    long long ans=solve(n,m);
    cout<<ans<<"\n";
    

    return 0;
}
