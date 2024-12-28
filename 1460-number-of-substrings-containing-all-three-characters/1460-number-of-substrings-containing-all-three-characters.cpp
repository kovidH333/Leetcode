class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int n = s.size();
        int hash[3] = {0};
        int typecnt = 0;
        long long cnt = 0;

        for(int r=0; r<n; r++){
            if(hash[s[r]-'a'] == 0) typecnt++;
            hash[s[r]-'a']++;

            while(typecnt>2){
                hash[s[l]-'a']--;
                if(hash[s[l]-'a'] == 0) typecnt--;
                l++;
            }

            cnt += r-l+1;
        }
        return static_cast<long long>(n) * (n + 1) / 2 - cnt;
    }
};