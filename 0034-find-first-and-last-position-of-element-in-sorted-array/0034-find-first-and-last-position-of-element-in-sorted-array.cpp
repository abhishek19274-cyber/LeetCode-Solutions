class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
        int n = nums.size();
        int low =0;
        int high = n-1;
        int ans = n;
        while(low <= high ){
            int mid = low + ((high - low )>>1);
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerbound(nums, target);
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        int last = lowerbound(nums, target + 1) - 1;
        
        return {first, last};
    }
};