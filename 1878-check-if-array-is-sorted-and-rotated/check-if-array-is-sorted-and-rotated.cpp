class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>copy(nums.size());
        for(int i=0;i<nums.size();i++){
            copy[i]=nums[i];
        }

        sort(copy.begin(),copy.end());

        
        vector<int>concate;
        concate.insert(concate.end(),nums.begin(),nums.end());
        concate.insert(concate.end(),nums.begin(),nums.end());

        auto it = search(concate.begin(), concate.end(), copy.begin(), copy.end());
        bool exists = (it != concate.end());

        return exists;
    }
};