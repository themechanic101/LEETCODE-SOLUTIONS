class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
     for(int i=0;i<nums.size();i++){
        int n=target-nums[i];
        for(int j=i+1;j<nums.size();j++){
          
           if(n==nums[j]){
            ans.push_back(i);
            ans.push_back(j);
            break;
           }
        }
     }
     return ans;
    }
};