class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, count = 0, ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            count += (nums[r] % 2);
            while (count > k) {
                count -= (nums[l] % 2);
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};