class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);

        sort(nums.rbegin(),nums.rend());
        vector<int>ans;

          int curr=0;

          for(int i=0;i<nums.size();i++){
            total-=nums[i];
            curr+=nums[i];
            ans.push_back(nums[i]);

            if(curr>total)return ans;
          }
        return ans;
    }
};