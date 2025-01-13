class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlen = strs[0].size();
        for(int i=1; i<strs.size(); i++){
            int len = strs[i].size();
            minlen = min(minlen,len);
        }
        string res;
        for(int i=0; i<minlen; i++){
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i] != strs[0][i]) return res;
            }
            res += strs[0][i];
        }
        return res;
    }
};