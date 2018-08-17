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
int n,m;
vi a;
int l,r;

int main()
{   ios::sync_with_stdio(false);
    cin>>n>>m;
    a.resize(m+1);
    REP(i,0,n){
        cin>>l>>r;
        for(int j=l;j<=r;j++ ){
            a[j]=1;
        }
    }
    int ans=0;
    vi b;
    REP(i,1,m+1){
        if(a[i]==0){
            ans++;
            b.PB(i);
        }
    }
    cout<<ans<<"\n";
    REP(i,0,ans){
        cout<<b[i]<<" ";
    }

    return 0;
}