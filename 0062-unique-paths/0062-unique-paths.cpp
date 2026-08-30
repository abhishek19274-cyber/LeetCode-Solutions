class Solution {
public:
    int solution(int i,int j,vector<vector<int>>& dp){
        if(i==0 and j == 0){
            return dp[0][0] = 1;
        }
        if(i <0 or j <0)return 0;
        if(dp[i][j]!= -1)return dp[i][j];
        int up = solution(i-1,j,dp);
        int down = solution(i,j-1,dp);
        return dp[i][j] = up+down;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solution(m-1,n-1,dp);
    }
};