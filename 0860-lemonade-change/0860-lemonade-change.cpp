class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5=0,count_10=0,count_20 =0;
        for(auto ele : bills){
            if(ele == 5){
                count_5++;
            }
            else if(ele == 10 and count_5 >=1){
                count_10++;
                count_5--;
            }
            else if(ele == 20 ){
                if(count_10 >=1 and count_5 >=1){
                    count_10--;
                    count_5--;
                    count_20++;
                }
                else if(count_5 >= 3){
                    count_5-=3;
                    count_20++;
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }

        }  
        return true;  
    }
};