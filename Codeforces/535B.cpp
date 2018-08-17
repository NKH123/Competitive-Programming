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
    int n;
    cin>>n;
    int N=n;
    unsigned int ans;
    vi dig;
    int rem;
    while(N!=0)
    {
        dig.PB(N%10);
        N/=10;
    }
    REP(i,0,dig.size())
    {
        if(i==0)
        {
            ans=0;
        }
        ans=ans+(1<<i);
    }

    vi::iterator it;
    while(dig.size()!=0)
    {
        it=dig.end();
        it--;
        if(*it == 7)
        {
            ans=ans+(1<<(dig.size()-1));
        }
        dig.pop_back();
    }
   
    cout<<ans;
    return 0;
}
