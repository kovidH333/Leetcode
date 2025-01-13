class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int val = 0;
        int prev = 0;
        for(int i=0; i<s.size(); i++){
            prev = val;
            if(s[i]=='(') val = val - 1;
            else val = val + 1;

            if(val != 0 && prev !=0) res = res+s[i];
        }
        return res;
    }
};