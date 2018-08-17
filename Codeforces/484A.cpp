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
    long long l,r, ans, temp;
    while(n--)
    {   
        cin>>l>>r;
        ans=l;
        int k=0;

        while(ans<=r && k<=62)
        { 
            if((l&(1LL<<k))==0)
            {  
                if((temp=ans|(1LL<<k))<=r)
                {
                    ans=ans|(1LL<<k);
                    
                }
            }
            k++;
        }
        cout<<ans<<"\n";

    }
    return 0;
}
