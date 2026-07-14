class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 and nums[j] == nums[j - 1])
                    continue;
                int k = n - 1;
                int l = j + 1;
                while (l < k) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum < (long long)target) {
                        l++;
                    } else if (sum > (long long)target) {
                        k--;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[k]};
                        result.push_back(temp);
                        l++;
                        k--;
                        while (l < k and nums[l] == nums[l - 1]) {
                            l++;
                        }
                        while (l < k and nums[k]==nums[k+1]){
                            k--;
                        }
                    }
                }
            }
        }
        return result;
    }
};