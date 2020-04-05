class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r=0;
        int l=0;
        while(l<nums.size() && r<nums.size()){
            if(l==r){
                r++;
            }
            else{
                if(nums[l]!=0){
                    l++;
                }
                else{
                    if(nums[r]==0){
                        r++;
                    }
                    else{
                        swap(nums[l],nums[r]);
                        l++;
                        r++;
                    }
                }
            }
        }
    }
};