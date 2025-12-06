class Solution {
public:
    int minimum(vector<vector<int>>&dp,int row,int col,vector<vector<int>>& grid){
        if(row<0 || col<0)return 1e9;
        if(row==0 && col==0)return grid[0][0];
        if(dp[row][col]!=-1) return dp[row][col];
        int up=grid[row][col]+minimum(dp,row-1,col,grid);
        int down=grid[row][col]+minimum(dp,row,col-1,grid);
        return dp[row][col]=min(up,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return minimum(dp,row-1,col-1,grid);
    }
};