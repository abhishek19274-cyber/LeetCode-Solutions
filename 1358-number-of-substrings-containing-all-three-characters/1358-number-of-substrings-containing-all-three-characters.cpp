class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,ans =0;
        vector<int> hash(3,-1);
        for(int r=0;r<s.size();r++){
            hash[s[r]-'a'] = r;
            if(hash[0] >=0 and hash[1]>=0 and hash[2]>=0){
                ans += *min_element(hash.begin(),hash.end())+1;
            }
        }
        return ans;
    }
};