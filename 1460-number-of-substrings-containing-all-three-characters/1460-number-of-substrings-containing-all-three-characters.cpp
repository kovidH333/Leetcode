// 

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int hash[3] = {-1,-1,-1};
        int cnt = 0;
        
        for(int r=0; r<s.size(); r++){
            hash[s[r]-'a'] = r;
            cnt += min({hash[0],hash[1],hash[2]})+1;
        }
        return cnt;
    }
};