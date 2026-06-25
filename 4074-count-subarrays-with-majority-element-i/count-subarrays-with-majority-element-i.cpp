class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int t) {
        int n=nums.size();

        int ans=0;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]==t)cnt++;

                int l=j-i+1;

                if(cnt>l/2)ans++;
            }

        }

        return ans;
    }
};