<h2>permutations Notes</h2><hr>class Solution {
public:
    void permutations(vector<int>&ds, vector<int>&nums, vector<vector<int>>&ans,int frq[] ){
        // base case
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size(); i++){
            if(!frq[i]){
                ds.push_back(nums[i]);
                frq[i]=1;
                permutations(ds,nums,ans,frq);
                frq[i]=0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        int frq[nums.size()];
        for(int i =0;i<nums.size();i++) frq[i]=0;

        permutations(ds,nums , ans,frq);

        return ans;
        
    }
};

