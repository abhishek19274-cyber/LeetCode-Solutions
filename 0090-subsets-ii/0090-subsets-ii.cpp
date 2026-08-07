
class Solution {
public:
    void backtrack(int start, std::vector<int>& nums, std::vector<int>& temp, std::vector<std::vector<int>>& result) {
        result.push_back(temp);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            backtrack(i + 1, nums, temp, result);
            temp.pop_back(); 
        }
    }
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        backtrack(0, nums, temp, result);
        return result;
    }
};