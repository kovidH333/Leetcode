class Solution {
public:
    int minimumLength(string s) {
        if(s.size() < 3) return s.size();

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int res = 0;
        for(auto it: freq){
            if((it.second)%2 == 1) res+= 1;
            else res += 2;
        }
        return res;
    }
};