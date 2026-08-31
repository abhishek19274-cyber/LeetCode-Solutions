class Solution {
public:
    int solution(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) return -1e9;
        if (i == grid.size() - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxe = -1e9;
        for (int i1 = -1; i1 <= 1; i1++) {
            for (int j = -1; j <= 1; j++) {
                int value = 0;
                if (j1 == j2) {
                    value = grid[i][j1];
                } else {
                    value = grid[i][j1] + grid[i][j2];
                }
                value += solution(i + 1, j1 + i1, j2 + j, grid, dp);
                maxe = max(maxe, value);
            }
        }
        return dp[i][j1][j2] = maxe;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solution(0, 0, m - 1, grid, dp);
    }
};