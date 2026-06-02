class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        

        for(int i=0;k>0 && i<nums.size() && nums[i]<0 ;i++,k--){
                 nums[i]=-nums[i];
        
        }

       int ans=accumulate(nums.begin(),nums.end(),0);
       int mini=*min_element(nums.begin(),nums.end());
       if(k%2==0)return ans;
       else if(k%2==1)return ans-mini*2;

        return ans;
    }
};