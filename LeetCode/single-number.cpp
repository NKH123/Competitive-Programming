class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto g:nums){
            ans=ans^g;
        }
        return ans;
    }
};