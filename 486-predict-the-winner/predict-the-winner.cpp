class Solution {
public:

bool solve(bool turn ,int p1,int p2 ,int left,int right,vector<int>&nums){
    if(left>right){
        return p1>=p2;
    }

    if(turn){
        return solve(!turn,p1+nums[left],p2,left+1,right,nums)||
         solve(!turn,p1+nums[right],p2,left,right-1,nums);
    }
    return solve(!turn,p1,p2+nums[left],left+1,right,nums) && 
    solve(!turn ,p1,p2+nums[right],left,right-1,nums);
}
    bool predictTheWinner(vector<int>& nums) {
        return solve(true,0,0,0,nums.size()-1,nums);
    }
};