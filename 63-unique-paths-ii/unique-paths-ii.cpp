class Solution {
public:
bool check(vector<vector<int>>& obstacleGrid,int row,int col){
    if(obstacleGrid[row][col]==1)return false;
    return true;
}


int paths(vector<vector<int>>& obstacleGrid,int row ,int col,vector<vector<int>>&dp){
        if(row<0 || col<0) return 0; // out of bound
     if(obstacleGrid[row][col]==1)return 0;
     if(row==0 && col==0)return 1;//base condition

    if(dp[row][col]!=-1)return dp[row][col]; // remove overlapping
    // if(!check(obstacleGrid,row,col))return 0;
    return dp[row][col]=paths(obstacleGrid,row-1,col,dp)+paths(obstacleGrid,row,col-1,dp);
    
     

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int row=obstacleGrid.size();
       int col=obstacleGrid[0].size();

       vector<vector<int>>dp(row,vector<int>(col,-1));

   return paths(obstacleGrid,row-1,col-1,dp);
    }
};