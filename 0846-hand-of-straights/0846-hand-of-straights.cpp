class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0 )return false;
        unordered_map<int,int> count;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto ele : hand){
            count[ele]++;
        }
        for(auto ele : count){
            pq.push(ele.first);
        }
        while(!pq.empty()){
            int first = pq.top();
            if(count[first]==0){
                pq.pop();
                continue;
            }
            for(int i=0;i<groupSize;i++){
                int nextcard = first+i;
                if(count[nextcard]==0){
                    return false;
                }
                count[nextcard]--;
            }
        }
        return true;
    }
};