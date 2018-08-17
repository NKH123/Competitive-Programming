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
int n, q, l, r,j=0;
 
cin>>n>>q;
vi a(n);
REP(i,0,n)
cin>>a[i];
unsigned int ans;
vector<pair <int, int> > b[31];
 
REP(i,0,31)
{   b[i].resize(n);
    for(j=0;j<n;j++)
    {
        if(j!=0)
    {
        b[i][j].F=b[i][j-1].F;
        b[i][j].S=b[i][j-1].S;
    }
        l=a[j]&(1<<i);
        if(l)
        {
            b[i][j].F++;
               //cout<<"b["<<i<<"]["<<j<<"].F="<< b[i][j].F<<"\n";
 
 
        }
        else
        {
            b[i][j].S++;
            //cout<<"b["<<i<<"]["<<j<<"].S="<< b[i][j].S<<"\n";
        }
    }
//cout<<"b["<<i<<"]["<<j<<"].F="<< b[i][j-1].F<<"\n";
//cout<<"b["<<i<<"]["<<j<<"].S="<< b[i][j-1].S<<"\n";
}
 
int cond1, cond2;
while(q--)
{   ans=0;
    cin>>l>>r;
    for(int k=30;k>=0;k--)
    {
        if(l==1)
    {
       cond1=abs(b[k][r-1].F-0);
       cond2=abs(b[k][r-1].S-0);
    }
    else {
        cond1=abs(b[k][r-1].F-b[k][l-2].F);
       cond2=abs(b[k][r-1].S-b[k][l-2].S);
    }
        if(cond1<cond2)
        {
            ans=ans+(1<<k);
 
            //cout<<"Partial ans="<<ans<<" added "<<(1<<k)<<"\n";
           // cout<<abs(b[k][r-1].F-b[k][l-1].F)<<" "<<abs(b[k][r-1].S-b[k][l-1].S)<<endl;
        }
    }
 
    cout<<ans<<"\n";
}