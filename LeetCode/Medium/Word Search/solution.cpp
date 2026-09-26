class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }
        if (board[row][col] != word[index]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (dfs(board, word, newRow, newCol, index + 1)) {
                return true;
            }
        }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};