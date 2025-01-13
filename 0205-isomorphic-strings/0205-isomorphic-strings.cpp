class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        map<char, int> mp1;
        string ans1;
        for(int i=0; i<s.size(); i++){
            if(mp1.find(s[i]) == mp1.end()){
                int len = mp1.size();
                mp1[s[i]] = len+1;
            }
            ans1 += ('0' + mp1[s[i]]);
        }

        map<char, int> mp2;
        string ans2;
        for(int j=0; j<t.size(); j++){
            if(mp2.find(t[j]) == mp2.end()){
                int leng = mp2.size();
                mp2[t[j]] = leng+1;
            }
            ans2 += ('0' + mp2[t[j]]);
        }

        return (ans1 == ans2);
    }
};