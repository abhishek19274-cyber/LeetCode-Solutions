class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int n = nums.size();
        int curr=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=1){
                max_count=max(max_count,curr);
                curr=0;
            }
            else{
                curr++;
            }
        }
        max_count = max(max_count,curr);
        return max_count;
    }
};