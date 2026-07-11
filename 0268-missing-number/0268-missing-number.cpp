class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_n =0;
        int nums_xor =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            xor_n^=i;
            nums_xor^=nums[i];
        }
        return nums_xor^xor_n^n;
    }
};