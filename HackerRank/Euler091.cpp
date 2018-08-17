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
int fun(int a, int b)
{
    int ret=0;
    int m1=a; int m2=b;
    while(__gcd(m1, m2)!=1)
    {
        int temp=__gcd(m1,m2);
        m1/=temp;
        m2/=temp;
    }
    int left=a; int up=b;
    while(left>=0 && up<=n)
    {
        left-=m2;
        up+=m1;
       ret++;
    }
    ret--;
    int right=a; int down=b;
    while(right<=n && down>=0)
    {
        right+=m2;
        down-=m1;
        ret++;
    }
    ret--;
    return ret;
}
int main()
{   ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans=0;
    REP(i,1,n+1)
    REP(j,1,n+1)
    {
        ans+=fun(i,j);
    }
    ans+=3*n*n;
    cout<<ans;
    return 0;
}