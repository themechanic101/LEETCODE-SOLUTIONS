class Solution {
public:

int solve(int i,int j,string &w1,string &w2,vector<vector<int>>&dp){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];

    if(w1[i]==w2[j])return dp[i][j]= solve(i-1,j-1,w1,w2,dp);
    else 
    return dp[i][j]= 1+min(solve(i-1,j-1,w1,w2,dp),min(solve(i-1,j,w1,w2,dp),solve(i,j-1,w1,w2,dp)));
}
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=n;i++){
            dp[0][i]=i;
        }
          for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }

        return dp[m][n];
    }
};