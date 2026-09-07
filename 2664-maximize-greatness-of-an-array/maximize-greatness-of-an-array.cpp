class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        int i=0,j=0;
        while(j<n){
            if(nums[j]>nums[i]) {
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
        
    }
};