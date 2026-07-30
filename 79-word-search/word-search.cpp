class Solution {
public:
    int m, n;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool dfs(vector<vector<char>>& mat, string& s, int idx, int row, int col) {
        if (idx == s.size()-1)
            return true;

        char ch = mat[row][col];
        mat[row][col] = '.';

        for (int i = 0; i < 4; i++) {
            int nxtr = row + dx[i], nxtc = col + dy[i];
            if (nxtr < m && nxtc < n && nxtr >= 0 && nxtc >= 0 &&
                s[idx + 1] == mat[nxtr][nxtc]) {
                if(dfs(mat, s, idx + 1, row + dx[i], col + dy[i])){
                    mat[row][col]=ch;
                    return true;
                }
            }
        }
        mat[row][col] = ch;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        bool found = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    found = dfs(board, word, 0, i, j);
                }
                if (found)
                    return true;
            }
        }
        return found;
    }
};