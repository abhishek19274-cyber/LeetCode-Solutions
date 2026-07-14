class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    int curr_j = nums[j];
                    int curr_k = nums[k];
                    while(j < k && nums[j] == curr_j) {
                        j++;
                    }
                    while(j < k && nums[k] == curr_k) {
                        k--;
                    }
                }
                else if(sum < 0){
                    int curr_j = nums[j];
                    while(j < k && nums[j] == curr_j) {
                        j++;
                    }
                }
                else {
                    int curr_k = nums[k];
                    while(j < k && nums[k] == curr_k) {
                        k--;
                    }
                }
            }
        }
        return result;
    }
};