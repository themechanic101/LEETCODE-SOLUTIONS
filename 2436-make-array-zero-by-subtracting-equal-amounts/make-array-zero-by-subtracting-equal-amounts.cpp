class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> hash;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++){
            if(nums[i]>0)   hash.insert(nums[i]);
        }
     
           
        return hash.size();
    }
};