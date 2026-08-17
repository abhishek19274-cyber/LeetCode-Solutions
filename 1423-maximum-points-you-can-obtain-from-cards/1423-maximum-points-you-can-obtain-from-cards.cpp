class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum =0,lsum=0,rsum=0,right_index=cardPoints.size()-1;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int ans = lsum;
        for(int i = k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[right_index];
            right_index--;
            ans = max(ans,lsum+rsum);
        }
        return ans;
    }
};