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
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    int ans;
    if(x1==x2 || y1==y2)
    ans=2*(abs(x1-x2)+abs(y1-y2)+3);
    else ans=2*(abs(x1-x2)+abs(y1-y2)+2);
    cout<<ans;

    return 0;
}