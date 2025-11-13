class Solution {
public:
bool backtrack(vector<int>& nums, vector<bool>& visited, int k, int start, int currSum, int target) {
       
        if (k == 1) return true;

   
        if (currSum == target)
            return backtrack(nums, visited, k - 1, 0, 0, target);


        for (int i = start; i < nums.size(); i++) {
            if (visited[i] || currSum + nums[i] > target) continue;

           visited[i] = true; 
            if (backtrack(nums, visited, k, i + 1, currSum + nums[i], target))
                return true;
            visited[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
         int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;

        int target = total / k;
        sort(nums.rbegin(), nums.rend()); 

        if (nums[0] > target) return false; 

        vector<bool> visited(nums.size(), false);
        return backtrack(nums, visited, k, 0, 0, target);
    }
        
    
};