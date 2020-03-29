#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define sz(x) (int)(x.size())
#define mod 1000000007
#define endl "\n"





int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    while(t--){
        int n, d;
        cin>>n>>d;
        a.clear();
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        int ans=a[0];
        for(int i=1;i<n;i++){
            while(d>=(i) && a[i]>0){
                ans++;
                a[i]--;
                d-=i;
            }
        }
        cout<<ans<<"\n";

    }

    return 0;
}