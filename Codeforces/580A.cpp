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
    REP(i,0,n)
    cin>>a[i];
    int len=1;
    int ans=1;
    REP(i,0,n)
    {
        if(a[i]>=a[i-1])
        ans++;
        else{
            ans=1;
        }
        len=max(len,ans);
    }
    cout<<len;
    return 0;
}