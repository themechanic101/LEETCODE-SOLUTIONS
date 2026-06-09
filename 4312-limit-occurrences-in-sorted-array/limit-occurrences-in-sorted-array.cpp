class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
     
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]<k){
                arr.push_back(nums[i]);
                mp[nums[i]]++;
            }
        }
        return arr;
    }
};