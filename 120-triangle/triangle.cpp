class Solution {
public:
//int minimum(vector<vector<int>>&triangle ,int r,int col, vector<vector<int>>dp){
//       if(r==triangle.size()-1)return triangle[r][col] ;

//       if(dp[r][col]!=INT_MIN)return dp[r][col];
//       int m=minimum(triangle,r+1,col,dp);
//       int n=minimum(triangle,r+1,col+1,dp);

//       return dp[r][col]=triangle[r][col]+min(m,n);

// }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
        vector<int> dp(triangle.back()); 

        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }

        return dp[0];

    }
};