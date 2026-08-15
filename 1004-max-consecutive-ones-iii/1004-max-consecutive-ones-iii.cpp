class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len = 0,l=0,zero =0;
        for(int r =0;r<nums.size();r++){
            if(nums[r]==0){
                zero++;
            }
            if(zero > k){
                while (zero > k) {
                if (nums[l] == 0) {
                    zero--;
                }
                l++;
            }
            }
            max_len = max(max_len,r-l+1);
        }
        return max_len;
    }
};