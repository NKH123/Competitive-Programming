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

int main()
{   ios::sync_with_stdio(false);
    long long n,k;
    cin>>n >>k;
    long long ans;
    if(k==1)
    {
        ans=n;
    }
    else
    {   k=62;
        ans=0;
        while(k>=0)
        {
            if((n&(1LL<<k) ) )
            {
                ans+= (1LL<<(k+1))-1;
                break;
            }
            k--;
        }
    }
    cout<<ans;
    return 0;
}
