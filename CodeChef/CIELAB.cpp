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
{   int a,b;
    cin>>a>>b;
    int c=a-b;
    int d;
    vi e;
    int C=c;
    while(C!=0)
    {   e.PB(C%10);
        C=C/10;
        d++;
    }
    if(e[0]!=1)
    e[0]=1;
    else
    e[0]=2;
    while(e.size()!=0)
    {
        C=C+e[e.size()-1];
        C=C*10;
        e.pop_back();
    }
    C=C/10;
    cout<<C;
    return 0;
}