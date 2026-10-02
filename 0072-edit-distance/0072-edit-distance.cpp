class Solution {
public:
    int solution(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        if(i < 0)return j+1;
        if(j< 0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j] = solution(i-1,j-1,word1,word2,dp);
        }
        int insert = 1+solution(i,j-1,word1,word2,dp);
        int delete_ =1+solution(i-1,j,word1,word2,dp);
        int replace = 1+solution(i-1,j-1,word1,word2,dp);
        return dp[i][j] = min(insert,min(delete_,replace));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solution(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};