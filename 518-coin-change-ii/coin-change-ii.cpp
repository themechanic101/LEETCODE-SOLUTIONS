class Solution {
public:
    int change(int amount, vector<int>& coins) {
         vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for(int coin : coins){
            for(int rem = coin; rem <= amount; rem++){
                dp[rem] += (int)dp[rem - coin];
            }
        }

        return dp[amount];
        // int n = coins.size();

        // vector<vector<long long>> dp(amount + 1, vector<long long>(n + 1, 0));

        
        // for (int idx = 0; idx <= n; idx++) {
        //     dp[0][idx] = 1;
        // }

    
        // for (int idx = n - 1; idx >= 0; idx--) {
        //     for (int rem = 1; rem <= amount; rem++) {

        //         long long notake = dp[rem][idx + 1];

        //         long long take = 0;
        //         if (coins[idx] <= rem) {
        //             take = dp[rem - coins[idx]][idx];
        //         }

        //         dp[rem][idx] = take + notake;
        //     }
        // }

        // return (int)dp[amount][0];
    }
};