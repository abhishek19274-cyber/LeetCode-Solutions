class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        solution(0,s,path,result);
        return result;
    }
    void solution(int index,string s,vector<string> &path,vector<vector<string>> &result){
        if(index == s.size()){
            result.push_back(path);
            return;
        }
        for(int i = index;i<s.size();++i){
            if(is_palindrome(s,index,i)){
                path.push_back(s.substr(index,i - index+1));
                solution(i+1,s,path,result);
                path.pop_back();
            }
        }
    }
    bool is_palindrome(string s,int start,int end){
        while(start <= end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};