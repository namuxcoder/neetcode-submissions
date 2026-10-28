class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<string> seen;

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                char x = board[row][col];
                if (x != '.') {
                    char value = board[row][col];
                    string key(1,value);
                    if (!seen.insert(key+" row " + to_string(row)).second) return false;
                    if (!seen.insert(key+" col " + to_string(col)).second) return false;
                    if (!seen.insert(key+" box " + to_string(row/3) + "-" + to_string(col/3)).second) return false;
                }
            }
        }

        return true;
    }
};
