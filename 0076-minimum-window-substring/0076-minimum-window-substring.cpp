class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return "";
        int start_index = -1, min_len = INT_MAX, l = 0, count = 0;
        vector<int> hash(128, 0);
        for (char c : t) {
            hash[c]++;
        }
        for (int r = 0; r < n; r++) {
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;
            while (count == m) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_index = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
        }
        return (start_index == -1) ? "" : s.substr(start_index, min_len);
    }
};