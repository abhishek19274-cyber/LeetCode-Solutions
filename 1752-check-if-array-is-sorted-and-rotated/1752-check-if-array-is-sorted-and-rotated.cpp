class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int min_index = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[(i - 1 + n) % n]) {
                min_index = i;
            }
        }
        int curr = min_index;
        int i = (curr + 1) % n;
        while (i != min_index) {
            if (nums[curr] > nums[i]) {
                return false;
            }
            curr = i;
            i = (curr + 1) % n;
        }
        
        return true;
    }
};