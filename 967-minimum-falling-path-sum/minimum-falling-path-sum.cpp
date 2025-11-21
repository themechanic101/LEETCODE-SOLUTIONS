class Solution {
public:
long long  minimum(vector<vector<int>>&matrix , int row ,int col ,  vector<vector<long long>>&dp){
    if(col<0 || col>matrix.size()-1)return INT_MAX;
    if(row==0) return matrix[0][col];
    if(dp[row][col]!=100000) return dp[row][col];
// kjhjkh
    long long up=matrix[row][col]+minimum(matrix,row-1,col,dp);
    long long  d_left=matrix[row][col]+minimum(matrix,row-1,col-1,dp);
    long long d_right=matrix[row][col]+minimum(matrix,row-1,col+1,dp);

    return dp[row][col]=min({up,d_left,d_right});
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<long long>>dp(n,vector<long long>(n,1e5));
        long long ans =INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,minimum(matrix,n-1,i,dp));
        }

        return ans;
    }
};