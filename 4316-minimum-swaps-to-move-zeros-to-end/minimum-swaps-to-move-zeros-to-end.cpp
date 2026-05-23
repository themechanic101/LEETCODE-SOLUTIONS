class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zeros=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==0)zeros++;
        }

        int cnt=0;
        for(int i=0;i<n-zeros;i++){
            if(nums[i]==0)cnt++;
        }

        return cnt;
    }
};