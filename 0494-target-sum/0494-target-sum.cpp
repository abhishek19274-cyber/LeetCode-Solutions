class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto ele : nums) sum += ele;
        if (abs(target) > sum || (sum + target) % 2 != 0) return 0;
        int new_target = (sum + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(new_target + 1, 0));
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        if (nums[0] <= new_target) dp[0][nums[0]] += 1;
        if (nums[0] == 0) dp[0][0] = 2;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= new_target; j++) {
                int pick = (nums[i] <= j) ? dp[i - 1][j - nums[i]] : 0;
                int not_pick = dp[i - 1][j];
                dp[i][j] = pick + not_pick;
            }
        }
        return dp[n - 1][new_target];
    }
};