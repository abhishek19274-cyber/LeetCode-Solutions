#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int index, const string& num, int target, long long current_val, long long prev_operand, string path, vector<string>& result) {
        if (index == num.size()) {
            if (current_val == target) {
                result.push_back(path);
            }
            return;
        }
        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0') break;
            string part = num.substr(index, i - index + 1);
            long long val = stoll(part);

            if (index == 0) {
                backtrack(i + 1, num, target, val, val, part, result);
            } else {
                backtrack(i + 1, num, target, current_val + val, val, path + "+" + part, result);
                backtrack(i + 1, num, target, current_val - val, -val, path + "-" + part, result);
                backtrack(i + 1, num, target, (current_val - prev_operand) + (prev_operand * val), prev_operand * val, path + "*" + part, result);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        backtrack(0, num, target, 0, 0, "", result);
        return result;
    }
};