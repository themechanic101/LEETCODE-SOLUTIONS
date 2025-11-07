class Solution {
public:
void permutations(vector<vector<int>>&ans,vector<int>&ds,vector<int>&nums,vector<int>&visited) {
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<nums.size();i++){
       if(visited[i])continue;
       if (i>0 && nums[i]==nums[i-1] &&visited[i-1]==0)continue;
        visited[i] = 1;
        ds.push_back(nums[i]);
        permutations(ans,ds, nums, visited);
        ds.pop_back();
        visited[i] = 0;
    }
}   
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>visited(nums.size(),0);
        sort(nums.begin(),nums.end());
        permutations(ans,ds,nums,visited);

        return ans;
    }
};