class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxlen = 0;
        int maxfreq = 0;
        int hash[26] = {0};

        for(int right=0; right<s.size(); right++){
            hash[s[right]-'A']++;
            maxfreq = max(maxfreq, hash[s[right]-'A']);

            if((right-left+1)-maxfreq > k){
                hash[s[left]-'A']--;
                left++;
            }else{
                maxlen = max(maxlen, right-left+1);
            }
        }
        return maxlen;
    }
};