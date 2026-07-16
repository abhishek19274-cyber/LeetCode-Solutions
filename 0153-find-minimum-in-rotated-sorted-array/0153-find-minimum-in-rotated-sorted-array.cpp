class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
        int min_element = INT_MAX;
        while(low<= high ){
            int mid = low + ((high - low)>>1);
            if(nums[low] <= nums[mid]){
                min_element =min(min_element,nums[low]);
                low = mid +1;
            }
            else{
                min_element =min(min_element,nums[mid]);
                high =high-1;
            }
        }
        return min_element;
    }
};