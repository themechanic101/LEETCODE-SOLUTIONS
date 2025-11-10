class Solution {
public:
int money(vector<int>&nums,int index,vector<int>&dp){
    if(index<0)return 0;
    if(index==0) return nums[0];

    if(dp[index]!=-1) return dp[index];

    int yes=nums[index]+money(nums,index-2,dp);

    int no=money(nums,index-1,dp);

    return dp[index]=max(yes,no);


}
public:
    int rob(vector<int>& nums) {
      int n =nums.size();
      vector<int>dp(n+1,-1);
      return money(nums,n-1,dp);
    }
};