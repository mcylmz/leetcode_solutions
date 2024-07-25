class Solution {
public:
    bool valid(vector<vector<char>>& board, int i, int j, char c) {
        for (int k = 0; k < 9; k++) {
            if (k != j && board[i][k] == c) {
                return false;
            }

            if (k != i && board[k][j] == c) {
                return false;
            }

            int ri = (3 * (i / 3)) + (k / 3);
            int ci = (3 * (j / 3)) + (k % 3);
            if (ri != i && ci != j && board[ri][ci] == c) {
                return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!valid(board, i, j, board[i][j])) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};