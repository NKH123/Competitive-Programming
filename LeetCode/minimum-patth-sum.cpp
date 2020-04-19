class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int> >dp;
        dp.resize(grid.size(),vector<int>(grid[0].size(),1000000000));
        dp[0][0]=grid[0][0];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i!=0){
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                }
                if(j!=0){
                    dp[i][j]=min(dp[i][j],grid[i][j]+dp[i][j-1]);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};