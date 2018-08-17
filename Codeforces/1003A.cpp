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
vi a;
int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    REP(i,0,n){
        int m;
        cin>>m;
        a.PB(m);
    }
    sort(a.begin(),a.end());
    int ans=1;
    int temp=1;
    for(int i=1; i<n; i++){
        if(a[i]==a[i-1]){
            temp++;
        }
        ans=max(ans,temp);
        if(i!=n-1 &&  a[i+1]!=a[i]){
            temp=1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}