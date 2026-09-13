class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rs = s;
        reverse(rs.begin(),rs.end());
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        for (int i = 0; i <= s.size(); i++) {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i = 1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s[i-1] == rs[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s.size()][s.size()];
    }
};