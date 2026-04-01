class Solution {
public:
    bool possible(vector<int>& nums, int threshold, int mid) {

        int sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += ceil((double)(nums[j]) / (double)(mid));
        }
        if (sum <= threshold) {
            return true;
        }

        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, threshold, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};