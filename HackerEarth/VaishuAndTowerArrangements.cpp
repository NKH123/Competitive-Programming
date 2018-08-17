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

int main()
{   ios::sync_with_stdio(false);
    int t,n;
    vi a;
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        REP(i,0,n)
        cin>>a[i];
        vi b(n,0);
        if(a[0]==1)
        b[0]=1;
        REP(i,0,n){
        if(i!=0){
                b[i]=b[i-1];
                if(a[i]==1)
                b[i]++;
            }

        }
        int ans=2*b[0]+n-1-b[n-1];
        REP(i,1,n-1)
        {
             ans=min(ans,2*b[i]+n-1-i-b[n-1]);
        }
         cout<<ans<<"\n";
    }
    return 0;
}
