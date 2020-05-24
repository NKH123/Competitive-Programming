/*
* @problem: 
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
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
#define mod 1000000007LL
#define bitcnt(x) __builtin_popcountll(x)
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
#define pi acos(-1.0)
#define ff first
#define ss second

using namespace std;
int n, m, color[210], in[210], d, D;
vector<int> v[210];

bool dfs(int src, int par) {
	if (color[src] == -1)
		color[src] = 1 - color[par];
	else if (color[src] == color[par])
		return 0;
	else return 1;
	bool ans = 1;
	for (int i : v[src]) {
		if (i != par)
			ans = (ans & dfs(i, src));
	}
	return ans;
}

int main() {
	// #ifdef LOCAL_PROJECT
	// 	freopen("output1.txt", "r", stdin);
	// 	// freopen("../output.txt", "w", stdout);
	// #endif

	while (cin >> n) { // taking input till EOF
		if (n == -1) {
			continue; // if no graph given as input
		}
		cin >> m >> d >> D;
		int a, b;
		bool flag = 0; // flag = 1 implies graph is not correct
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (a > n || b > n || a < 1 || b < 1) // checking if the node number is in the range or not
				flag = 1;
			b += n; // renaming vertices of 2nd set as n + 1, n + 2, ... , n + n
			v[a].push_back(b); // constructing adjacency list
			v[b].push_back(a);
		}
		MS1(color);
		color[0] = 1;
		for (int i = 1; i <= 2 * n; i++) {
			if(color[i] == -1) {
				if (!dfs(i, 0)) // checking if graph is bi-partite or not
					flag = 1;
			}
		}
		for (int i = 1; i <= 2 * n; i++) {
			if (v[i].size() < d || v[i].size() > D) { // checking if degree of each vertex is >= d and <= D
				flag = 1;
			}
			v[i].clear(); // resetting the adjacency list
		}
		if (flag)
			cout << "incorrect\n" << endl;
	}
	return 0;
}