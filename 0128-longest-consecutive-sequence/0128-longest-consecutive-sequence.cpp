class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int max_len = INT_MIN;
        int curr_len =1;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i-1] == nums[i]-1){
                curr_len++;
            }
            else{
                max_len = max(max_len,curr_len);
                curr_len = 1;
            }
        }
        return max(max_len,curr_len);
    }
};