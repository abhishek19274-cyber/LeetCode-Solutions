class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        int n = nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                result[pos] = nums[i];
                pos = pos+2;
            }
            else{
                result[neg] = nums[i];
                neg = neg+2;
            }
        }
        return result;
    }
};