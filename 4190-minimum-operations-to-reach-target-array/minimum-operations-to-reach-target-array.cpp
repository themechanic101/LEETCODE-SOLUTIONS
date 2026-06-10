class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
       bool seen[100001]{};
       int ans = 0;
       for(int i = 0; i < nums.size(); i++){
        if(nums[i] != target[i] && !seen[nums[i]]){
            ans++;
            seen[nums[i]] = true;
        }
       }
       return ans;
    }
};