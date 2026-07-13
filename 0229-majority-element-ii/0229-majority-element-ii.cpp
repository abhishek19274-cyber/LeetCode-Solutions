class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MIN,ele2=INT_MIN;
        int cnt1=0,cnt2=0;
        for(const auto &ele : nums){
            if(ele == ele1){
                cnt1++;
            }
            else if(ele == ele2){
                cnt2++;
            }
            else if(cnt1 == 0){
                ele1 = ele;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                ele2 = ele;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> result;
        cnt1=0,cnt2=0;
        for(const auto &ele : nums){
            if(ele == ele1)cnt1++;
            else if(ele == ele2)cnt2++;
        }
        int min = (int)(nums.size()/3)+1;
        if(cnt1>=min)result.push_back(ele1);
        if(cnt2>=min)result.push_back(ele2);
        return result;
    }
};