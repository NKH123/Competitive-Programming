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
    a.resize(n);
    int sum=0;
    REP(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    sum=sum/2;
    if(sum==n-1)
    cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
