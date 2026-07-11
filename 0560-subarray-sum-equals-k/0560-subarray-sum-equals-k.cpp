class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> premap;
        premap[0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int remaining_sum = sum - k;
            if(premap.find(remaining_sum) != premap.end()){
                count += premap[remaining_sum];
            }
            premap[sum]++; 
        }
        return count;
    }
};