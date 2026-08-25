class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int num=k;
       int n=nums.size();

       if(nums[0]>k){
        return k;
       }

       for(int i=0;i<n;i++){
          if(num<nums[i]){
            return num;
          }
          else if(num<=nums[i]){
            num+=k;
          }
       } 
       return num;
    }
};