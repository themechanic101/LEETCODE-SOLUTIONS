class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            int count1 = 0;

            for (int num : nums) {
                if ((num >> bit) & 1) {
                    count1++;
                }
            }

            int count0 = n - count1;
            ans += 1LL * count1 * count0;
        }

        return ans;
    }
};