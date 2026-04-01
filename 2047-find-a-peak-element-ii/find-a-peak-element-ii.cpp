class Solution {
public:
    int getMax( vector<int>& nums) {
        int idx = 0;
        int maxVal = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int col = getMax(mat[mid]);

            int left   = (col - 1 >= 0) ? mat[mid][col - 1] : -1;
            int right  = (col + 1 < m) ? mat[mid][col + 1] : -1;
            int top    = (mid - 1 >= 0) ? mat[mid - 1][col] : -1;
            int bottom = (mid + 1 < n) ? mat[mid + 1][col] : -1;

            if (mat[mid][col] > left && mat[mid][col] > right &&
                mat[mid][col] > top && mat[mid][col] > bottom) {
                return {mid, col};
            } else if (top > mat[mid][col]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return {-1, -1};
    }
};