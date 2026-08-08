class Solution {
public:
    void solution(int i,int n,int k,vector<int> &temp,vector<vector<int>>& result){
        if(k==0 and n==0){
            result.push_back(temp);
            return;
        }
        if (i > 9 || k < 0 || n < 0) {
            return;
        }
        temp.push_back(i);
        solution(i+1,n-i,k-1,temp,result);
        temp.pop_back();
        solution(i + 1, n, k, temp, result);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> result;
        solution(1,n,k,temp,result);
        return result;
    }
};