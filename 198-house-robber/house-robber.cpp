class Solution {
// public:
// int money(vector<int>&nums,int index,vector<int>&dp){
//     if(index<0)return 0;
//     if(index==0) return nums[0];

//     if(dp[index]!=-1) return dp[index];

//     int yes=nums[index]+money(nums,index-2,dp);

//     int no=money(nums,index-1,dp);

//     return dp[index]=max(yes,no);


// }
public:
    int rob(vector<int>& nums) {
      int n =nums.size();
      vector<int>dp(n);
      if(n==0)return 0;
      if(n==1)return nums[0];

      dp[0]=nums[0];
      dp[1]=max(nums[0],nums[1]);

      for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
      }
      return dp[n-1];
    }
};