class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> unq;
        int n = s.size();
        int l=0,r=0,maxlen=0;

        while(r<n){
            if(unq.find(s[r]) == unq.end()){
                unq.insert(s[r]);
                maxlen = max(maxlen, r-l+1);
                r++;
            }else{
                unq.erase(s[l]);
                l++;
            }
        }
        return maxlen;
    }
};