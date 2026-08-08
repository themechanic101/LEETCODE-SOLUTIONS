class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int Gcd=gcd(nums[i],nums[j]);
                long long temp=(1LL*nums[i]*nums[j])/(1LL*Gcd*Gcd);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};