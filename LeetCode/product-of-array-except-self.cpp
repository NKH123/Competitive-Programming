class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prod(nums.size()+1);
        prod[0]=1;
        for(int i=0;i<nums.size();i++){
            prod[i+1]=prod[i]*nums[i];
        }
        int R=1;
        vector<int>ans;
        for(int i=(int)nums.size()-1;i>=0;i--){
                ans.push_back(prod[i]*R);
                R=R*nums[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};