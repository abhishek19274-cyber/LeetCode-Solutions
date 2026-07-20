class Solution {
public:
    bool helperfunction(vector<int>& nums, int k,int mid){
        int curr_sum =0;
        int count =1;
        for(auto ele : nums){
            if(curr_sum + ele > mid){
                count++;
                curr_sum = ele;
            }
            else curr_sum+=ele;
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low + ((high-low)>>1);
            if(helperfunction(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};