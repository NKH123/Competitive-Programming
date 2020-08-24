#include<bits/stdc++.h>
using namespace std;

void dfs(int cur, int par, vector<int>& dp, vector<int>& values, vector<vector<int> >& adj, int &ans) {
	int val = values[cur];
	deb(cur);
	vector<int>max_two;
	max_two.clear();
	for (auto child : adj[cur]) {
		if (child != par) {
			dfs(child, cur, dp, values, adj, ans);
			max_two.push_back(dp[child]);

		}
	}
	if(max_two.size() != 0)
	sort(max_two.begin(), max_two.end());
	dp[cur] = val;
	int N = max_two.size();
	if (N >= 1)
	dp[cur] = val + max(0,max_two[N-1]);	ans = max(ans, dp[cur]);
	if (N >= 2)
	ans= max(ans, val + max(0,max_two[N-1]) + max(0,max_two[N-2]) );
}

int bestSumAnyTreePath(vector<int> parent, vector<int> values) {
	// Find root and build graph using adjacency lists
	vector<vector<int> > adj;
	adj.clear();
	adj.resize(parent.size() + 5);
	int root = -1;
	for (int i = 0; i < parent.size(); i++) {
		if (parent[i] ==  -1) {
			root = i;
		}
		else{
			adj[parent[i]].push_back(i);
			adj[i].push_back(parent[i]);
		}

	}
	// Initialize DP, dp[i] strores the max sum of the path ending at node i
	vector<int> dp(parent.size() + 5, -1);
	// Do a dfs to populate the dp values
	int ans  = 0;
	dfs(root, -1, dp, values, adj, ans);
	return ans;

}


int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>parent(n);
    for(int i = 0; i < n; i++){
    	cin>>parent[i];
    }
    cin>>n;
    vector<int>values(n);
    for (int i = 0; i < n; i++){
    	cin>>values[i];
    }
    cout<<bestSumAnyTreePath(parent, values)<<"\n";
    return 0;
}