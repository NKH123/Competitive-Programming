#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>a;
    vector<int>dp;
    int fun(int N){
        if(dp[N]!=-1)return dp[N];
        if(N==0)return dp[N]=1;
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(N<a[i])continue;
            ans+=fun(N-a[i]);
        }
        return dp[N]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1);
        for(int i=0;i<=target;i++){
            dp[i]=-1;
        }
        a.resize(nums.size());
        for(int i=0;i<a.size();i++){
            a[i]=nums[i];
        }
        int ans=fun(target);
        return ans;
    }
};