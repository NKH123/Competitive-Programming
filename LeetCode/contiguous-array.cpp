class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]--;
            }
        }
        int n=nums.size();
        vector<int>pref(n+1,0);
        map<int, int>M;
        M.clear();
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        for(int i=0;i<n;i++){
            M[pref[i+1]]=i+1;
        }
        int ans=0;
        for(int i=0;i<(n);i++){
                int J=M[pref[i]];
                ans=max(ans,(J)-(i));
        }
        return ans;
        
    }
};