class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int longest =1;
        unordered_set<int> s;
        for(const auto& ele : nums){
            s.insert(ele);
        }
        for(const auto& ele : s){
            if(s.find(ele-1)==s.end()){
                int cnt = 1;
                int x = ele;
                while(s.find(x+1)!=s.end()){
                    x = x+1;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};