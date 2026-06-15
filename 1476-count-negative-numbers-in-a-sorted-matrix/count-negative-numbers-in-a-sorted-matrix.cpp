// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int cnt=0;

//         int m=grid.size();
//         int n=grid[0].size();

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]<0)cnt++;
//             }
//         }

//         return cnt;
//     }
// };
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = m - 1; 
        int j = 0;     

        int res = 0;

        while (i >= 0 && j < n) {
            if (grid[i][j] < 0) {
                res += n - j;
                i--;
            } else
                j++;
        }

        return res;
    }
};
