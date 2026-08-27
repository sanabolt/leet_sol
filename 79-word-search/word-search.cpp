class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int idx) {

        if (idx == word.size())
            return true;

        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] != word[idx])
            return false;

        char ch = board[r][c];
        board[r][c] = '#';

        bool ans =
            dfs(board, word, r + 1, c, idx + 1) ||
            dfs(board, word, r - 1, c, idx + 1) ||
            dfs(board, word, r, c + 1, idx + 1) ||
            dfs(board, word, r, c - 1, idx + 1);

        board[r][c] = ch;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        if (word.size() > rows * cols)
            return false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0] &&
                    dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};