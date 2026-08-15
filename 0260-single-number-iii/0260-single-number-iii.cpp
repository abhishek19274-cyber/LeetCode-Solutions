class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XOR =0;
        for(auto ele : nums)XOR^=ele;
        long long right_most_bit = (XOR & (XOR-1))^XOR;
        int b1=0,b2 =0;
        for(auto ele : nums){
            if(ele & right_most_bit )b1^=ele;
            else b2^= ele;
        }
        return {b1,b2};
    }
};