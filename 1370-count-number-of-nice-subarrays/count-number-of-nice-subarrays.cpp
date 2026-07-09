class Solution {
public:
 int solve(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n = nums.size();
        int subs = 0;
        int cnt = 0;
        int r = 0, l = 0;

        while(r < n){
            if(nums[r] % 2 != 0) cnt++; // Found an odd number

            // If we exceed our budget of k odd numbers, shrink from the left
            while(cnt > k){
                if(nums[l] % 2 != 0) cnt--;
                l++;
            }

            // All subarrays from l to r are valid
            subs += r - l + 1;
            r++;
        }
        return subs;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //excatly_k=atmost_k-atmost_k-1
       return solve(nums,k)-solve(nums,k-1);
        
    }
};