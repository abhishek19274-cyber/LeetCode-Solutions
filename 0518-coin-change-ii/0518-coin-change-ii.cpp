class Solution {
public:
    int solution(int index ,int amount, vector<int>& coins,vector<vector<int>> &dp){
        if(index ==0 ){
            return (amount%coins[index]==0);
        }
        if(dp[index][amount] !=-1)return dp[index][amount];
        int not_take =solution(index-1,amount,coins,dp);
        int take =0;
        if(coins[index] <= amount){
            take = solution(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount] = not_take + take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solution(coins.size()-1,amount,coins,dp);
    }
};