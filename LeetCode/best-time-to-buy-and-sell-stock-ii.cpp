class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        if(prices.size()==0){
            return 0;
        }
        int cur=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>cur){
                ans+=(prices[i]-cur);
                cur=prices[i];
            }
            else{
                cur=min(cur,prices[i]);
            }
        }
        return ans; 
    }
};