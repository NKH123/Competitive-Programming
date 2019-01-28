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
//freopen("a.in", "r", stdin);
//freopen("b.in", "r", stdin);
//freopen("c.in", "r", stdin);
//freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    int n,k;
    vi a;
    while(t--){
        cin>>n>>k;
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        sort(a.begin(),a.end(),greater<int>());
        /*REP(i,0,n){
            cout<<a[i]<<" ";
        }
        cout<<"\n";*/
        int ans;
        ans=k-1;
        //cout<<"before ans="<<ans<<"\n";
        k--;
        int max=a[k];
        
        for(int i=k;i<n;i++){
            if(a[i]<max){
                break;
                //cout<<"a[i]="<<a[i]<<" max="<<max<<"\n";
            }
            ans++;
        }
        cout<<ans<<"\n";

    }

    return 0;
}