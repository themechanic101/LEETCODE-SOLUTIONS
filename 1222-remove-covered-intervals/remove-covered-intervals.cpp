class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n=arr.size();
        int cnt=0;
       sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0]; 
        });
        int maxr=0;
      for(auto &t:arr){
         if(t[1]>maxr){
            cnt++;
            maxr=t[1];
         }
      }

        return cnt;
    }
};