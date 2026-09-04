class Solution {
public:
    int solution(int index, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (target == 0) return 0;
        if (index == 0) return (target % coins[0] == 0) ? target / coins[0] : 1e9;
        if (dp[index][target] != -1) return dp[index][target];

        int not_pick = solution(index - 1, target, coins, dp);
        int pick = (coins[index] <= target) ? 1 + solution(index, target - coins[index], coins, dp) : 1e9;

        return dp[index][target] = min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = solution(coins.size() - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};