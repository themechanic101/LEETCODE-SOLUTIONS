class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int t) {
       int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == t ? 1 : -1);
        }

        int ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (pref[r + 1] - pref[l] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};