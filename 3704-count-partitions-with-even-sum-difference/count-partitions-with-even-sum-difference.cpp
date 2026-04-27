class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int prefix=0;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            prefix+=nums[i];
            if(abs(prefix-(sum-prefix))%2==0) cnt++;
        }

        cout<<cnt<<endl;
        return cnt;
    }
};