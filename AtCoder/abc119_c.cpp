    #include <bits/stdc++.h>
    using namespace std;
     
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define endl "\n"
    #define int long long
     
    const int N=1e5+5;
     
    int n, ans=1e9;
    int len[N];
    int a, b, c;
     
    int rec(int idx, int i, int j, int k)
    {
    	if(idx==n+1)
    	{
    		if(i==0 || j==0 || k==0)
    			return 1e9;
    		return abs(i-a) + abs(j-b) + abs(k-c);
    	}
    	int ans=1e9;
    	ans=min(ans, rec(idx+1, i, j, k));
    	if(i==0)
    		ans=min(ans, rec(idx+1, i+len[idx], j, k));
    	if(j==0)
    		ans=min(ans, rec(idx+1, i, j+len[idx], k));
    	if(k==0)
    		ans=min(ans, rec(idx+1, i, j, k+len[idx]));
    	if(i>0)
    		ans=min(ans, 10 + rec(idx+1, i+len[idx], j, k));
    	if(j>0)
    		ans=min(ans, 10 + rec(idx+1, i, j+len[idx], k));
    	if(k>0)
    		ans=min(ans, 10 + rec(idx+1, i, j, k+len[idx]));
    	return ans;
    }
     
    int32_t main()
    {
    	IOS;
    	cin>>n>>a>>b>>c;
    	for(int i=1;i<=n;i++)
    		cin>>len[i];
    	int ans=rec(1, 0, 0, 0);
    	cout<<ans;
    	return 0;
    }