#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool backtrack(int i, int j, int index, int n, int m, const string& word,
                   vector<vector<char>>& board) {
        if (index == word.size())
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = backtrack(i + 1, j, index + 1, n, m, word, board) ||
                     backtrack(i - 1, j, index + 1, n, m, word, board) ||
                     backtrack(i, j + 1, index + 1, n, m, word, board) ||
                     backtrack(i, j - 1, index + 1, n, m, word, board);
        board[i][j] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(i, j, 0, n, m, word, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};