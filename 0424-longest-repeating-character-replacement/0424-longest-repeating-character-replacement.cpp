class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0,l=0,count =0,max_freq=0;
        vector<int> hash(26,0);
        for(int r =0;r<s.size();r++){
            hash[s[r]-'A']++;
            max_freq = *max_element(hash.begin(),hash.end());
            if((r-l+1)-max_freq > k){
                hash[s[l]-'A']--;max_freq =0;
                l++;
            }
            if((r-l+1)-max_freq <= k){
                max_len = max(max_len,r-l+1);
            }
        }
        return max_len;
    }
};