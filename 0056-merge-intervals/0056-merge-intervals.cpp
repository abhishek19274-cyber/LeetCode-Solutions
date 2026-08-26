class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> pair;
        vector<vector<int>> result;
        pair.push_back(intervals[0][0]);
        pair.push_back(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start > pair[1]) {
                result.push_back(pair);
                pair.pop_back();
                pair.pop_back();
                pair.push_back(start);
                pair.push_back(end);
                continue;
            }
            pair[0] = min(start, pair[0]);
            pair[1] = max(end, pair[1]);
        }
        result.push_back(pair);
        return result;
    }
};