class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++){
            if(matrix[0][i]!=0)  dp[0][i] = 1;
        }
          
        for (int i = 0; i < m; i++){
            if(matrix[i][0]!=0) dp[i][0] = 1;
        }
           

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else {
                    dp[i][j] =
                        min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) +1;
                        
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                cnt += dp[i][j];
            }
        }

        return cnt;
    }
};