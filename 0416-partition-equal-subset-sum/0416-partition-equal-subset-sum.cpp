class Solution {
public:
    bool solution(int index, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (index == 0) return arr[0] == sum;
        if (dp[index][sum] != -1) return dp[index][sum];
        bool not_included = solution(index - 1, sum, arr, dp);
        bool included = false;
        if (arr[index] <= sum) {
            included = solution(index - 1, sum - arr[index], arr, dp);
        }
        return dp[index][sum] = (included || not_included);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(auto ele : nums){
            sum+=ele;
        }
        if(sum%2!=0){
            return false;
        }
        sum = sum/2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solution(n - 1, sum, nums, dp);
    }
};