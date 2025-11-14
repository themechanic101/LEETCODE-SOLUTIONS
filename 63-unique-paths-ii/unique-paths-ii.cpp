class Solution {
public:


// int paths(vector<vector<int>>& obstacleGrid,int row ,int col,vector<vector<int>>&dp){
//         if(row<0 || col<0) return 0;
//      if(obstacleGrid[row][col]==1)return 0;
//      if(row==0 && col==0)return 1;

//     if(dp[row][col]!=-1)return dp[row][col];
//     // if(!check(obstacleGrid,row,col))return 0;
//     return dp[row][col]=paths(obstacleGrid,row-1,col,dp)+paths(obstacleGrid,row,col-1,dp);
    
     

// }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int row=obstacleGrid.size();
       int col=obstacleGrid[0].size();

       vector<vector<int>>dp(row,vector<int>(col,1));
       if(row<0 || col<0)return 0;
       if(obstacleGrid[0][0]==1)return 0;
       dp[0][0]=1;

       for (int j = 1; j < col; j++) {
        if (obstacleGrid[0][j] == 1) dp[0][j] = 0;
        else dp[0][j] = dp[0][j - 1];
    }


    for (int i = 1; i < row; i++) {
        if (obstacleGrid[i][0] == 1) dp[i][0] = 0;
        else dp[i][0] = dp[i - 1][0];
    }

       for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(obstacleGrid[i][j]==1)dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
       }

   return dp[row-1][col-1];
    }
};