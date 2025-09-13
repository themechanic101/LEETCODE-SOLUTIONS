class Solution {
public:

int binary_search(vector<int>& nums, int target, int low ,int high){ 
        if(low>high) return -1;
        int mid = low+(high-low)/2;
        if(nums[mid]==target) return mid;
        else if (target>nums[mid])  return binary_search(nums,target,mid+1,high);
     else return binary_search(nums,target,low,mid-1);
        }
    int search(vector<int>& nums, int target) {
      return binary_search(nums,target,0,nums.size()-1); 
    }
};