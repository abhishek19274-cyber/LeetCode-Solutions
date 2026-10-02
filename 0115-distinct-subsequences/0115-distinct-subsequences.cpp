class Solution {
public:
    int solution(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(j <0)return 1;
        if(i <0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = solution(i-1,j-1,s,t,dp)+solution(i-1,j,s,t,dp);
        }
        return dp[i][j] = solution(i-1,j,s,t,dp);

    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solution(s.size()-1,t.size()-1,s,t,dp);
    }
};