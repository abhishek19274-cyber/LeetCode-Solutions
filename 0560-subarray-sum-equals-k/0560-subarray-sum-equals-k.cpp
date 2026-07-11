class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> premap;
        premap[0] = 1;
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remaining = sum - k;

            if (premap.find(remaining) != premap.end()) {
                count += premap[remaining];
            }
            premap[sum]++;
        }
        return count;
    }
};