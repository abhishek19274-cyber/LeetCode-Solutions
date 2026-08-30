class Solution {
public:
    int solution(int i,int j,int sum,vector<vector<int>>& grid, vector<vector<int>>& dp){
        if( i == 0 and j ==0)return dp[i][j] =grid[i][j];
        if(i<0 or j<0)return INT_MAX;
        if(dp[i][j]!=-1 )return dp[i][j];
        int up = solution(i-1,j,grid[i][j],grid,dp);
        int left = solution(i,j-1,grid[i][j],grid,dp);
        return dp[i][j] = grid[i][j]+min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solution(n-1,m-1,0,grid,dp);
    }
};