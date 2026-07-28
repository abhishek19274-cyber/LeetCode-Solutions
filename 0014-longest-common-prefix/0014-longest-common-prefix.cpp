class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        sort(strs.begin(),strs.end());
        string result =  "";
        int min_itr = min(strs[0].size(),strs[strs.size()-1].size());
        for(int i =0;i < min_itr;i++){
            if(strs[0][i] != strs[strs.size()-1][i]){
                return result;
            }
            result = result + "" + strs[0][i];
        }
        return result;
    }
};