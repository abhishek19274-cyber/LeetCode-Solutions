class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // use of Moore's Voting algorithm
        int n = nums.size();
        int count =1 ;
        int curr = nums[0];
        for(int i=1;i<n;i++){
            if(curr != nums[i] and count==0){
                curr = nums[i];
                count = 1;
            }
            else if(curr == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return curr;
    }
};