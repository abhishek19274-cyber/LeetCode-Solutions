class Solution {
public:
    bool helperfunction(vector<int>& piles, int h,int mid){
        long long total_time_taken = 0;
        for(auto ele : piles){
            total_time_taken+=(ele + mid-1)/mid;
        }
        return total_time_taken <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        const long long  N= 1e9;
        long long low =1;
        long long high = *max_element(piles.begin(), piles.end());
        while(high-low>1){
            long long mid = low + ((high - low)>>1);
            if(helperfunction(piles,h,mid) == false){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        if(helperfunction(piles,h,low)==true)return low;
        if(helperfunction(piles,h,high)==true)return high;
        return -1;
    }
};