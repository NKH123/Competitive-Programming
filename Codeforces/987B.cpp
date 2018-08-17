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
    long long x, y;
    cin>>x>>y;
    double a, b;
    char f;
    if(x>2 && y>2)
    {
        if(x==y)
            f='e';
        if(x>y)
        {
            f='l';
        }
        if(x<y)
        {
            f='g';
        }
    }
    else
    {
        a=(log(x))/(float)x;
    b=(log(y))/(float)y;
   // cout<<"a="<<a<<"  b="<<b<<"\n";
        if(a==b)
            f='e';
        if(a>b)
        {
            f='g';
        }
        if(a<b)
        {
            f='l';
        }}
        switch(f)
        {

            case 'e':cout<<"=";break;
            case 'g':cout<<">"; break;
            case 'l': cout<<"<"; break;
        }
    return 0;
}