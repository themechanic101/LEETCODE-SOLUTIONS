class Solution {
public:
int solve(vector<int>& p,int idx,int buy,vector<vector<int>>&dp){
    if(idx>=p.size())return 0;
  
    if(dp[idx][buy]!=-1)return dp[idx][buy];

    int profit=0;

    if(buy==0){
        profit=max(solve(p,idx+1,buy,dp),solve(p,idx+1,!buy,dp)-p[idx]);
    }
    if(buy==1){
        profit=max(solve(p,idx+1,buy,dp),p[idx]+solve(p,idx+2,!buy,dp));
    }

    return dp[idx][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
       return solve(prices,0,0,dp);
    }
};
