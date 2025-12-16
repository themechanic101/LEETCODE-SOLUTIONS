class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        unordered_map<int,int>mp;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
        }

        for(auto &p:mp){
           if(p.second>n)ans.push_back(p.first);
        }

        return ans;
    }
};