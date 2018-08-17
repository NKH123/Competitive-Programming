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
    int n, k;
   cin>>n>>k;
   vi v(256,-1);
   int i, j;

    while(n--)
    {
        int x;
        cin>>x;
        if(v[x] == -1)
        {   
            if((x-k+1)>0)
                {
                    i=x-k+1;
                }
                else  i=0;
            for(;i<=x;i++)
            {
                if(v[i]==-1||v[i]==i)
                {
                    for (int j = i;j <= x;j++)
                        v[j] = i;
                    break;
                }
            }
        }
        cout<<v[x]<<" ";
    }
    return 0;
}
