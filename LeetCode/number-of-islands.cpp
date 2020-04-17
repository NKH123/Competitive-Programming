class Solution {
public:
    vector<vector<int> >vis;
    vector<vector<char> >G;
    void dfs(int I, int J){
        vis[I][J]=1;
        
        //up
        if(I-1>=0 && G[I-1][J]=='1' && vis[I-1][J]==0){
            dfs(I-1,J);
        } 
        //left
        if(J-1>=0 && G[I][J-1]=='1' && vis[I][J-1]==0){
            dfs(I,J-1);
        }
        
        //right
        if(J+1<G[0].size() && G[I][J+1]=='1' && vis[I][J+1]==0){
                dfs(I,J+1);
        }
        
        //down
        if(I+1<vis.size() && G[I+1][J]=='1' && vis[I+1][J]==0){
            dfs(I+1,J);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0){
            return 0;
        }
        G=grid;
        int ans=0;
        vis.resize(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(G[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    dfs(i,j);
                }
            }
        }
        return ans;
    }
};