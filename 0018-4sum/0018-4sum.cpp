class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans_set;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                unordered_set<long long> hash;
                for(int k = j + 1; k < n; k++){
                    long long required = (long long)target - nums[i] - nums[j] - nums[k];
                    if(hash.find(required) != hash.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)required};
                        sort(temp.begin(), temp.end());
                        ans_set.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> result(ans_set.begin(), ans_set.end());
        return result;
    }
};