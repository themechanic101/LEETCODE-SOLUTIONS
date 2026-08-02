// class Solution {
// public:

// int solve(int idx,int cnt,vector<int>&prices,int buy,vector<vector<vector<int>>> &dp){
//     if(idx>= prices.size() || cnt==2)return 0;
//     if(dp[idx][buy][cnt]!=-1)return dp[idx][buy][cnt];

//     int profit=0;

//     if(buy==0){
//         profit=max(solve(idx+1,cnt,prices,0,dp),solve(idx+1,cnt,prices,1,dp)-prices[idx]);
//     }
//     if(buy==1){
//         profit=max(solve(idx+1,cnt,prices,1,dp),solve(idx+1,cnt+1,prices,0,dp)+prices[idx]);
//     }

//     return dp[idx][buy][cnt]=profit;
// }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//         return solve(0,0,prices,0,dp);
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap < 3; cap++)
                {
                    if(buy)
                    {
                       dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], 0 + dp[ind+1][1][cap]);
                    }else
                    {
                       dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind +1][0][cap]);
                    }
                }
            }
        }
        
        return dp[0][1][2];

    }
};