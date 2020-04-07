class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<int>ct(2000,0);
        for(int i=0;i<arr.size();i++){
            ct[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<1998;i++){
            if(ct[i+1]>0){
                ans+=ct[i];
            }
        }
        return ans;
    }
};