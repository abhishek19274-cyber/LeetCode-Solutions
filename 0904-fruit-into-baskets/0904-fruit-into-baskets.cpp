class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l =0,max_len =0;
        unordered_map<int,int> hash;
        for(int r =0;r< fruits.size();r++){
           hash[fruits[r]]++;
           if(hash.size() >2){
                while(hash.size() > 2){
                    hash[fruits[l]]--;
                    if(hash[fruits[l]]==0){
                        hash.erase(fruits[l]);
                    }
                    l++;
                }
           }
           if(hash.size() <= 2){
            max_len = max(max_len,r-l+1);
           }
        }
        return max_len;
    }
};