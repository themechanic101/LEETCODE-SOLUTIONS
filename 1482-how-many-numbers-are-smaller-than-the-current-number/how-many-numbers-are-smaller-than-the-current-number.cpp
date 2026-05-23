class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> counter(102);
        int n = nums.size();
        for (int i = 0 ; i < n; i++){
            counter[nums[i] + 1]++;
        }
        
        for (int i=1; i < counter.size(); i++){
            counter[i] = counter[i] + counter[i-1];
        }
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            ans[i] = counter[nums[i]];
        }
        return ans;
    }
};