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
string s;

vector <pair <int,int> > a;
a.resize(n);

REP(i,0,n)
{
    cin>>a[i].F;
    a[i].S=i+1;
}
sort(a.begin(),a.end());
cin>>s;
deque<int>b, c;
vi ans(2*n);
REP(i,0,n)
b.PB(a[i].S);
REP(i,0,2*n)
{
    if(s[i]=='0')
    {

        c.PB(b[0]);
        ans[i]=b[0];
        b.pop_front();
    }
    else
    {
        ans[i]=c.back();
        c.pop_back();
    }
    cout<<ans[i]<<" ";
}

return 0;
}
