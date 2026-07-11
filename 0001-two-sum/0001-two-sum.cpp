class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> sorted;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sorted.push_back({nums[i], i});
        }
        sort(sorted.begin(), sorted.end());
        int left = 0;
        int right = n - 1;
        while (left < right) {
            long long sum = sorted[left].first + sorted[right].first;
            if (sum == target) {
                break;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return {sorted[left].second, sorted[right].second};
    }
};