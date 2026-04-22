typedef __int128 ll;
class Solution {
public:
bool solve(vector<int>& nums,long long target,int idx,ll &curr){
     if(idx>=nums.size())return false;

     if(curr*nums[idx]==target)return true;
    ll temp=curr*nums[idx];

     bool take =solve(nums,target,idx+1,temp);
     bool notake=solve(nums,target,idx+1,curr);

     return take || notake;

}
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll product=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            product*=nums[i];
        }
        long double temp=target;
        if((long double)product/target != temp)return false;

        ll curr=1;

        return solve(nums,target,0,curr);
    }
};