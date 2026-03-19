class Solution {
public:
void subsetSumRecursive(vector<int>& nums, int idx, int target,int &cnt) {
    if(idx>=nums.size()){
        if (target == 0)
        cnt++;
        return;
    }  
    
          
 
    // if (nums[idx] > target) {
    //     return ;
    // }
 
     subsetSumRecursive(nums,idx+1, target - nums[idx],cnt);
     subsetSumRecursive(nums, idx+1, target,cnt);
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(nums.size()==1 && nums[0]<target)return 0;
        if((total+target)%2!=0)return 0;

        int sum=(total+target)/2;

        int cnt=0;
        subsetSumRecursive(nums,0,sum,cnt);
        return cnt;
    }
};