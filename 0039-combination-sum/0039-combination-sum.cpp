class Solution {
public:
    void sum(int i,int target,vector<int> &candidates,vector<int> temp,vector<vector<int>>& result){
        if(i == candidates.size()){
            if(target ==0 ){
                result.push_back(temp);
            }
            return;
        }
        if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            sum(i,target-candidates[i],candidates,temp,result);
            temp.pop_back();
        }
        sum(i+1,target,candidates,temp,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sum(0,target,candidates,temp,result);
        return result;
    }
};