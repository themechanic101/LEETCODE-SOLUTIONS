class Solution {
public:
    bool validity(vector<vector<char>>& board, char c, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c && i != row)
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c && i != col)
                return false;
        }

        int row_block = 3 * (row / 3);
        int col_block = 3 * (col / 3);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int r = row_block + i;
                int c2 = col_block + j;
                if (board[r][c2] == c && (r != row || c2 != col))
                    return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                char c = board[i][j];
                if (validity(board, c, i, j) == false)
                    return false;
            }
        }

        return true;
    }
};