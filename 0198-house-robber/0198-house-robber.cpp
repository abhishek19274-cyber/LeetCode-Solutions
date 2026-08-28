class Solution {
public:
    int solve(int i, vector<int>& nums,vector<int>& dp) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];
        if(dp[i]!=-1)return dp[i];
        int rob_current = nums[i] + solve(i - 2, nums,dp);
        int skip_current = solve(i - 1, nums,dp);
        return dp[i] = max(rob_current, skip_current);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums.size() - 1, nums,dp);
    }
};