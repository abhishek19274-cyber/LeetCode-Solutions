class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_pointer = -1;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero_pointer = i;
                break;
            }
        }
        if (zero_pointer == -1) return;
        for(int j = zero_pointer+1;j<n;j++){
            if(nums[j]!=0){
                swap(nums[j],nums[zero_pointer]);
                zero_pointer++;
            }
        }
    }
};