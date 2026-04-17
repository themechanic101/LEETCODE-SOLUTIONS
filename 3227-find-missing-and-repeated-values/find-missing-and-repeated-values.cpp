class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int size = n * n;
        vector<int> hash(size + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hash[grid[i][j]]++;
            }
        }

        int a = -1, b = -1;

        for (int i = 1; i <=size; i++) {
            if (hash[i] == 2) {
                a = i;
            }
           else if (hash[i] == 0) {
                b = i;
            }
        }

        return {a, b};
    }
};