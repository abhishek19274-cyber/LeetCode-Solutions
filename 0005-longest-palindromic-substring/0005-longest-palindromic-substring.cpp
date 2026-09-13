class Solution {
public:
    string longestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        for (int i = 0; i <= s.size(); i++) {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        int max_len = 0;
        int max_index = -1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (s[i - 1] == rs[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (i - dp[i][j] == s.size() - j) {
                        if (max_len < dp[i][j]) {
                            max_len = dp[i][j];
                            max_index = i - 1;
                        }
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        string answer = s.substr(max_index - max_len + 1, max_len);
        return answer;
    }
};