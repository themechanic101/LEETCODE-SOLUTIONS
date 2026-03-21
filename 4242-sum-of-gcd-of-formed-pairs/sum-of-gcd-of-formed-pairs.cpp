class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        vector<ll> prefix;
        ll mx=nums[0];
        for (int i = 0; i < nums.size(); i++) {
             mx = max((ll)nums[i],mx);
            int k = gcd(nums[i], mx);
            prefix.push_back(k);
        }
        sort(prefix.begin(), prefix.end());

        int l = 0, r = prefix.size() - 1;
        ll sum = 0;
        while (r > l) {
            ll temp = gcd(prefix[l], prefix[r]);
            sum += temp;
            l++;      
            r--;     
        }

        return sum;
    }
};