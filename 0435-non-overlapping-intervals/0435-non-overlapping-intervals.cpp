class cont{
    public:
    int start;
    int end;
    cont(int s,int e) :start(s),end(e){}
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<cont> temp;
        for(int i=0;i<intervals.size();i++){
            temp.push_back(cont(intervals[i][0],intervals[i][1]));
        }
        sort(temp.begin(),temp.end(),[](const cont& a,const cont& b){
            return a.end < b.end;
        });
        int removal = 0;
        int current_end =temp[0].end;
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i].start < current_end) {
                removal++;
            } else {
                current_end = temp[i].end;
            }
        }

        return removal;
    }
};