class Solution {
public:
    bool helperfunction(vector<int>& bloomDay, int m, int k, int mid){
        long long bq = 0;
        int adjacent_flower = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                adjacent_flower++;
                if(adjacent_flower == k){
                    bq++;
                    adjacent_flower = 0;
                }
            }
            else{
                 adjacent_flower = 0;
            }
        }
        return bq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m * k) return -1;
        long long low = 0; 
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        while(high - low > 1){
            long long mid = low + ((high - low) >> 1);
            if(helperfunction(bloomDay, m, k, mid)){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        return high;
    }
};