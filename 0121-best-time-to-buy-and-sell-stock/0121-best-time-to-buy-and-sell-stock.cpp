class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minp = prices[0];
        int profit = INT_MIN;
        int cost;
        for(int i = 1;i<n;i++){
            cost = prices[i]-minp;
            profit = max(profit,cost);
            minp = min(minp,prices[i]);     
        }
        return (profit < 0) ? 0 : profit;
    }
};