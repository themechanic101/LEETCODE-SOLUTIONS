class Solution {
public:
const long long M=1e9+7;
int dp[201][201][201];
int solve(vector<int>& nums,int idx,int g1,int g2){
    if(idx>=nums.size()){
        return (g1!=0 && g1==g2);
    }

    if(dp[idx][g1][g2]!=-1)return dp[idx][g1][g2];
    int ans=0;

    ans=solve(nums,idx+1,g1,g2);

    ans=(ans+solve(nums,idx+1,gcd(g1,nums[idx]),g2))%M;
    ans=(ans+solve(nums,idx+1,g1,gcd(g2,nums[idx])))%M;

    return dp[idx][g1][g2]=ans;

}

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,0);
    }
};