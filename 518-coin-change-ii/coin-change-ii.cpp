class Solution {
public:

    long long solve(vector<int>& coins, int rem, int idx,vector<vector<long long>>&dp) {
        if (rem == 0)
            return dp[rem][idx]=1;

            if(dp[rem][idx]!=-1)return dp[rem][idx];

        if (rem < 0 || idx >= coins.size()) {
            return dp[rem][idx]=0;
        }

        long long notake = solve(coins, rem, idx + 1,dp);
        long long take = 0;
        if (coins[idx] <= rem) {
             take = solve(coins, rem - coins[idx], idx,dp );
        }

        return dp[rem][idx]=take + notake;
    }
    int change(int amount, vector<int>& coins) {
        
     if(coins.empty())return 0;
        if (amount == 0)
            return 1;
            int n=coins.size();

       vector<vector<long long>>dp(amount+1,vector<long long>(n+1,-1));

        return solve(coins, amount, 0,dp);
    }
};