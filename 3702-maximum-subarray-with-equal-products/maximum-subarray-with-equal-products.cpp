class Solution {
public:
   int maxLength(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); ++i){
        long long gcdVal = nums[i], lcmVal = nums[i], prod = 1, maxLcm = 2520;
        for(int j = i; j < nums.size(); ++j){
            prod = prod*nums[j];
            if(prod > maxLcm) break;
            gcdVal = gcd(gcdVal, nums[j]);
            lcmVal = lcm(lcmVal, nums[j]);
            if(prod == gcdVal * lcmVal) ans = max(ans, j - i + 1);
        }
    }
    return ans;
}
};