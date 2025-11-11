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
        int i=m-1,j=n-1;
        return path(dp,i,j,m,n);
    }
};