#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits.h>
#include <vector>
#include <map>
#include <bitset>
#include <string>
#include <iterator>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <stack>
#include <algorithm>
#include <cstdlib>
#define MAX 100100
#define mod 1000000001LL
#define bitcnt(x) __builtin_popcount(x)
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))
#define ll long long int
#define mp(x, y) make_pair(x, y)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define in(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define ins(x) scanf("%s", x)
#define pr(x) printf("%lld\n", x)
#define prd(x) printf("%d\n", x)
#define prs(x) printf("%s\n", x)
#define pi acos(-1.0)
#define ff first
#define ss second
 
using namespace std;
int random(int l, int r) {
    int tmp = rand() % (r - l + 1);
    return tmp + l;
}
 
int main()
{
    freopen("input.txt", "w", stdout);
    //freopen("output.txt", "w", stdout);
    srand(time(NULL));
    int t = 2;
    cout << t << endl;
    while (t--) {
        int n = random(1, 100);
        int m = random(0, n * n);
        int d = random(1, n);
        int D = random(d, n);
        cout << n << " " << m << " " << d << " " << D << endl;
    }
    return 0;
}