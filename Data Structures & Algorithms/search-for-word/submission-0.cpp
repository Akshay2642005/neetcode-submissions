class Solution {
   public:
    int ROWS, COLS;
    set<pair<int, int>> path;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (dfs(board, word, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.length()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[i] ||
            path.count({r, c})) {
            return false;
        }

        path.insert({r, c});
        bool result = dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r - 1, c, i + 1) ||
                      dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r, c - 1, i + 1);
        path.erase({r, c});
        return result;
    }
};
