class Solution {
public:
    int solution(int i,int j,vector<vector<int>>& ob, vector<vector<int>> &dp){
        if(i ==0 and j==0 and (ob[i][j]!=1))return 1;
        if(i < 0 or j <0 )return 0;
        if( ob[i][j] == 1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up = solution(i-1,j,ob,dp);
        int left =solution(i,j-1,ob,dp);
        return dp[i][j] =up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return solution(obstacleGrid.size()-1,obstacleGrid[0].size()-1,obstacleGrid,dp);
    }
};