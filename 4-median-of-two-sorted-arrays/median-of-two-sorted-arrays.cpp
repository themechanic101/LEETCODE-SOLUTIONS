class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        double ans=0;

       
        vector<int> merged;
        for (int i = 0; i < n; i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            merged.push_back(nums2[i]);
        }

       
        sort(merged.begin(), merged.end());

        int total = merged.size();

        if (total % 2 == 1) {
           ans=merged[total/2];
       
        } else {
           
            double middle1 = merged[total / 2 - 1];
            double middle2 = merged[total / 2];
           ans=(middle1+middle2)/2;
    }
    return ans;
    }
};