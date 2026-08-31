class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        const long long INF = 1e18;
        vector<vector<long long>> dp(n, vector<long long>(n, INF));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                long long path1 = (j <= i - 1) ? dp[i - 1][j] : INF;
                long long path2 = (j > 0) ? dp[i - 1][j - 1] : INF;
                dp[i][j] = (long long)triangle[i][j] + min(path1, path2);
            }
        }
        long long result = INF;
        for (int i = 0; i < n; i++) {
            result = min(result, dp[n - 1][i]);
        }
        return (int)result;
    }
};