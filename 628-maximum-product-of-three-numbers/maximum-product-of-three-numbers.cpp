class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    int prod=1;
    int n=nums.size();

    sort(nums.begin(),nums.end());
    int max1=nums[n-1];
    int max2=nums[n-2];
    int max3=nums[n-3];

    int min1=nums[0];
    int min2=nums[1];
    int min3=nums[2];

    int minp=min1*min2*min3;
    int maxp=max1*max2*max3;
    int comb=max1*min1*min2;

     prod=max(minp,maxp);
     prod=max(comb,prod);
    return prod;
    }
};