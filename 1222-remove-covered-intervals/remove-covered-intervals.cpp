class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
   int n = intervals.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
           int a = intervals[i][0],b = intervals[i][1];
           for(int j=0;j<n;j++){
             if(j!=i && a>=intervals[j][0] && intervals[j][1]>=b){
                cnt++;
                break;
             }
           }
        }
        
        return n-cnt;
    }
};