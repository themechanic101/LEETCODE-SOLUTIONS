class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans(nums.size());
        int ind=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans[ind]=nums[i];
                ind++;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot){
                ans[ind]=nums[i];
                ind++;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                ans[ind]=nums[i];
                ind++;
            }
        }

        return ans;
    }
};