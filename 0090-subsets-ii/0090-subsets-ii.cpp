class Solution {
public:
    void solution(int i,vector<int>& nums,vector<int>& temp,set<vector<int>>& res){
        if(i==nums.size()){
            res.insert(temp);
            return;
        }
        solution(i+1,nums,temp,res);
        temp.push_back(nums[i]);
        solution(i+1,nums,temp,res);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        set<vector<int>> res;
        vector<vector<int>> result;
        solution(0,nums,temp,res);
        for(auto &ele : res){
            result.push_back(ele);
        }
        return result;
    }
};