class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>par(nums.size(),0);
        par[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            par[i]=par[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int sum=par[j];
                if(i!=0){
                    sum-=par[i-1];
                }
                if(sum==k){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};