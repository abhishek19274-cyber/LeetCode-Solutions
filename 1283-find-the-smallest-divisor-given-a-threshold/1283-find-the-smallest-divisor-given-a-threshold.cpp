class Solution {
public:
    bool helperfunction(vector<int>& nums, int threshold,int mid){
        int sum =0;
        for(auto ele : nums ){
            sum +=(ele + mid - 1) / mid;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =0;
        int high = *max_element(nums.begin(),nums.end());
        while(high-low>1){
            int mid = low+((high-low)>>1);
            if(helperfunction(nums,threshold,mid)){
                high= mid;
            }
            else{
                low=mid;
            }
        }
        return high;
    }
};