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

int main()
{   ios::sync_with_stdio(false);
    int n;
    int t, val;
    cin>>t;
    while(t--)
    {
         cin>>n;
        vector<vector <int> > a(n);
        REP(i,0,n)
        {
            for(int j=0;j<=i;j++)
            {cin>>val;
                a[i].PB(val);
        }}
        vector<vector <int> > b(n);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0; j<=i; j++)
            {
                if(i==n-1)
                {   val=a[i][j];
                    b[i].PB(val);
                }
                else
                {
                    val=a[i][j]+max(b[i+1][j],b[i+1][j+1]);
                    b[i].PB(val);
                }
            }
        }
        cout<<b[0][0]<<"\n";
    }
    return 0;
}
