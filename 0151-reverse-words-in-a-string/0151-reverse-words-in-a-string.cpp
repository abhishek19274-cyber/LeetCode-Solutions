class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string new_str = "";
        string curr_word = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                curr_word += s[i];
            }
            if ((s[i] == ' ' || i == s.size() - 1) && !curr_word.empty()) {
                reverse(curr_word.begin(), curr_word.end());
                if (!new_str.empty()) {
                    new_str += " ";
                }
                new_str += curr_word;
                curr_word = "";
            }
        }
        return new_str;
    }
};