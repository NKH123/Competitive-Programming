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
    string f, l;
    cin>>f>>l;
    string s;
    s.push_back(f[0]);
    for(int i=1;i<f.size();i++)
    {
        if(f[i]<l[0])
        {
            s.push_back(f[i]);
        }
        else break;
    }
    s.push_back(l[0]);
    cout<<s;

    return 0;
}