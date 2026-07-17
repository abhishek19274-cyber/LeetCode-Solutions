class Solution {
public:
    int mySqrt(int x) {
        long long low =1;
        long long high = x-1;
        long long ans = x;
        while(low<=high){
            long long mid = low +((high-low)>>1);
            if(mid*mid > x){
                high = mid-1;
            }
            else{
                ans = mid;
                low =mid+1;
            }
        }
        return ans;
    }
};