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
int a[1000008];
int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    vi A;
    set<int>ss;
    while(t--){
        memset(a,0,sizeof(a));
        
        int n;
        cin>>n;
        ss.clear();
        A.resize(n);
        REP(i,0,n){
            cin>>A[i];
            a[A[i]]++;
            ss.insert(A[i]);
        }
        ll ans=0;
        for(auto g:ss){
            for(int i=1;i<=a[g];i++){
                if(a[i]>=g ){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";

    }

    return 0;
}