class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int n = s.size();
        int l = 0;
        int curr_count = 0;
        int max_len = 0;
        for (int r = 0; r< n; r++) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            curr_count = r - l + 1;
            max_len = max(max_len, curr_count);
            hash[s[r]] = r;
        }
        return max_len;
    }
};