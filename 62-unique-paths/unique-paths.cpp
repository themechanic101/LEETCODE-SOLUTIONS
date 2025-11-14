class Solution {
public:
    int path( vector<vector<int>>&dp,int row,int col,int m,int n ){
        if(row==0 && col==0)return 1;//base condition
        if(row<0 || col<0) return 0; // out of bound
        if(dp[row][col]!=-1)return dp[row][col]; // remove overlapping
        return dp[row][col]=path(dp,row-1,col,m,n)+path(dp,row,col-1,m,n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if(m<0 || n<0)return 0;
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return abs(dp[m-1][n-1]);
    }
};