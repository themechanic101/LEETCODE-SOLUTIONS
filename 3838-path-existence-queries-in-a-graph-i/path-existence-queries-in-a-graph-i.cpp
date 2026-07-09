class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>group(n,0);

        int curr=0;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff)curr++;
            group[i]=curr;
        }

      vector<bool> ans(queries.size());

for (int i = 0; i < queries.size(); i++) {
    ans[i] = (group[queries[i][0]] == group[queries[i][1]]);
}
        return ans;
    }
};