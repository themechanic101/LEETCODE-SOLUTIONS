class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
         int mini=INT_MAX;
        for(int i=0;i<tasks.size();i++){
            int sum=0;
            for(int j=0;j<tasks[i].size();j++){
                sum+=tasks[i][j];
            }
            mini=min(mini,sum);
        }
        return mini;
    }
};