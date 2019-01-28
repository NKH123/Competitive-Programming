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
int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    ll x,y;
    ll ans=0;
    while(n--){
        cin>>x>>y;
        ans=max(ans,x+y);
    }
    cout<<ans<<"\n";

    return 0;
}