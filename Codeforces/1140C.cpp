#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define f first
#define s second

const int N = 1e6 + 5;

int n, k;
pair<int, int> a[N];

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    if(p1.s != p2.s)
        return p1.s < p2.s;
    return p1.f < p2.f;
}

int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].f>>a[i].s;
    sort(a + 1, a + n + 1, comp);
    multiset<int> s;
    int len = 0;
    int ans = 0;
    for(int i=n;i>=1;i--)
    {   
        int beauty = a[i].s;
        int sum = len + a[i].f;
        ans = max(ans, beauty * sum);
        s.insert(a[i].f);
        len += a[i].f;
        if(s.size() >= k)
        {
            len -= *s.begin();
            s.erase(s.begin());
        }
    }
    cout<<ans;
    return 0;
}