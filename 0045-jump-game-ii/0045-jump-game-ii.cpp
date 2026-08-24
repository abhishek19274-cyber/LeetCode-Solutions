class Solution {
public:
    int jump(vector<int>& nums) {
        long long l =0,jump =0,r=0;
        while(r < nums.size()-1){
            long long farthest =0;
            for(long long i=l;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }
            l = r+1;
            r = farthest;
            jump++;
        }
        return jump;
    }
};