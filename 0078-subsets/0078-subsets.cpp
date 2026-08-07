#include <vector>

class Solution {
public:
    void solution(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }
        solution(i + 1, nums, temp, result);
        temp.push_back(nums[i]);
        solution(i + 1, nums, temp, result);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        solution(0, nums, temp, result);
        return result;
    }
};