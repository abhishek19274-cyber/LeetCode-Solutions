class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int l = 0;
        int max_len = 0;
        for (int r = 0; r < fruits.size(); r++) {
            hash[fruits[r]]++;
            while (hash.size() > 2) {
                hash[fruits[l]]--;
                if (hash[fruits[l]] == 0) {
                    hash.erase(fruits[l]);
                }
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};