class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),lastindex=-1,maxi=-1;

        vector<int>dp(n,0),parent(n,-1),ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }

            if(dp[i]>maxi){
                lastindex=i;
                maxi=dp[i];
            }


           
        }
         int i=lastindex;

            while(parent[i]!=i){
                ans.push_back(nums[i]);
                i=parent[i];
            }
            ans.push_back(nums[i]);

            return ans;

    }
};