class Solution {
public:
    int solution(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(j<0 or j > i) return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i == 0)return dp[0][0] = triangle[0][0];
        int path1 = solution(i-1,j,triangle,dp);
        int path2 = solution(i-1,j-1,triangle,dp);
        return dp[i][j] = triangle[i][j] + min(path1,path2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int result = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i =0;i<n;i++){
            int curr = solution(n-1,i,triangle,dp);
            result = min(curr,result);
        }
        return result;
    }
};