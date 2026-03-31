class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        // Get the size of the array
        int n = nums.size();

        // Initialize low and high pointers for binary search
        int low = 0, high = n - 1;

        // Binary search loop
        while (low <= high) {
            // Calculate the middle index
            int mid = (low + high) / 2;

            // If the middle element is the target, return true
            if (nums[mid] == target)
                return true;

            // If the target is greater, move to the right half
            else if (target > nums[mid])
                low = mid + 1;

            // Otherwise, move to the left half
            else
                high = mid - 1;
        }

        // Return false if target not found
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();

        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {

                return binarySearch(matrix[i], target);
            }
           
        }
         return false;
    }
    };