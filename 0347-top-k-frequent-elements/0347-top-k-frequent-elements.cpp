class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto ele : nums){
            freq[ele]++;
        }
        vector<pair<int,int>> temp;
        for(auto ele : freq){
            temp.push_back({ele.second,ele.first});
        }
        sort(temp.rbegin(),temp.rend());
        vector<int> answer;
        for(int i=0;i<k;i++){
            answer.push_back(temp[i].second);
        }
        return answer;
    }
};