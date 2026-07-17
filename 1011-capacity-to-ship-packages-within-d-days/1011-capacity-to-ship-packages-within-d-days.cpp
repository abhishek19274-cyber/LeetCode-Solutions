class Solution {
public:
    bool helperfunction(vector<int>& weights, int days,int mid){
        int count =1;
        int sum =0;
        for(auto ele : weights){
            sum+=ele;
            if(sum > mid){
                count++;
                sum = ele;
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end())-1;
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(high - low >1){
            int mid = low +((high - low)>>1);
            if(helperfunction(weights,days,mid)){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        return high;
    }
};