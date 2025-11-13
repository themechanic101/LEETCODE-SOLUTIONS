class Solution {
public:
int solve(vector<vector<int>>& dungeon,int row,int col,vector<vector<int>>&dp){
      int m=dungeon.size();
        int n=dungeon[0].size();
     if(row==m-1 && col==n-1)return max(1,1-dungeon[row][col]);
     if(row>=m || col>=n)return 1e6;
     if(dp[row][col]!=-1)return dp[row][col];

    int right = solve( dungeon,row,col+1, dp);
        int down = solve( dungeon,row + 1, col, dp);

        int need = min(right, down) - dungeon[row][col];
        dp[row][col] = max(1, need);

        return dp[row][col];
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(dungeon,0,0,dp);
    }
};