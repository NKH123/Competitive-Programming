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
int n, l, x, r;
cin>>n>>l>>r>>x;
int tot=0;
unsigned int maxi=0;
vector <unsigned int> a(n);
int ans=0;
REP(i,0,n)
{
    cin>>a[i];
}
unsigned int mini;
REP(i,0,(1<<n))
{tot=0;
maxi=0;
mini=a[0]+1<<30;
//cout<<"In i="<<i<<" loop\n";
    REP(j,0,n)
    {
        //cout<<"In j="<<j<<" loop\n";
        if((i&(1<<j)))

        {   if(i==(1<<j))
            {   //cout<<"Forced to continue cuz of only one element in subset\n";
                continue;
            }

       //     cout<<"Inside if statement\n";
            tot=tot+a[j];
            maxi=max(maxi,a[j]);
            mini=min(mini,a[j]);
     //       cout<<"tot="<<tot<<"\nmaxi="<<maxi<<"\nmini="<<mini<<"\n";

        }}

   // cout<<"Outside j loop\n";
    if(tot<=r && tot>=l && (maxi-mini)>=x)
    {  // cout<<"Inside ans inc loop ******************************** i="<<i<<"\n";
        ans++;
    }

}
cout<<ans;


    return 0;
}
