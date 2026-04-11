class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans=0;

    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans=max(dp[i][j],ans);
                } else {
                
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                      ans=max(dp[i][j],ans);
                }
            }
        }
 
  return ans;
 }
    int minDistance(string word1, string word2) {
        int common=longestCommonSubsequence(word1,word2);
        int ans=0;
        int s1=word1.size()-common;
        int s2=word2.size()-common;
        ans=s1+s2;

        return ans;
    }
};