class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto ele : nums){
            freq[ele]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto ele : freq){
            heap.push({ele.second,ele.first});
            if(heap.size() >k ){
                heap.pop();
            }
        }
        vector<int> result;
        while(!heap.empty()){
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
        
    }
};