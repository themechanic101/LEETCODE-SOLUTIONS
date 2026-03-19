class Solution {
public:
    bool solve(vector<int>& nums, int i, int currsum, int target,vector<vector<int>>&dp) {
        if (currsum == target) return true;
        if (currsum > target || i >= nums.size()) return false;
        if(dp[i][currsum]!=-1)return dp[i][currsum];

     
        if (solve(nums, i + 1, currsum + nums[i], target,dp))
            return dp[i][currsum]=true;

      
        return dp[i][currsum]=solve(nums, i + 1, currsum, target,dp);
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return false;
        int k=total/2;

        vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));

        return solve(nums, 0, 0, total / 2,dp);
    }
};