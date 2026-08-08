class Solution {
public:
    void solution(string digits, vector<vector<char>> &mapping,vector<string> &result,string str ="",int i =0){
        if(i == digits.size()){
            result.push_back(str);
            return;
        }
        int num = digits[i] - '2';
        for(int j =0;j<mapping[num].size();j++){
            solution(digits,mapping,result,str+mapping[num][j],i+1);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<vector<char>> mapping ={
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','x','y','z'}
        };
        vector<string> result;
        solution(digits,mapping,result);
        return result;
    }
};