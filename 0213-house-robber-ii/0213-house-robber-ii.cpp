class Solution {
public:
    int function(vector<int>& nums){
        int prev =nums[0],prev2 = 0,curr = 0;
        for(int i=1;i<nums.size();i++){
            int take = nums[i] + ((i > 1) ? prev2 : 0);
            int not_take = 0 + prev;
            curr = max(take,not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> temp1,temp2;
        for(int i =0;i<nums.size();i++){
            if(i!= 0)temp1.push_back(nums[i]);
            if(i!=nums.size()-1)temp2.push_back(nums[i]);
        }
        return max(function(temp1),function(temp2));
    }
};