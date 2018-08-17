#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int n;
vi a[1005];
bool vt[1005];
int retnum(int x){
    for(auto g: a[x]){
        return g;
    }
}
int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    REP(i,0,n){
        int m;
        cin>>m;
        a[i+1].PB(m);
    }
    for( int i=1; i<=n;i++){
        memset(vt,false, sizeof(vt));
        //vt[i]=true;
        int j=i;
        while(vt[j]!=true){
            vt[j]=true;
            j=retnum(j);
        }
        cout<<j<<" ";
    }
    return 0;
}