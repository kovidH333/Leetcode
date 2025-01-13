class Solution {
public:
    string reverseWords(string s) {
        string res;
        string temp;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' '){
                if(!temp.empty()){
                    reverse(temp.begin(), temp.end());
                    if (!res.empty()) res += ' ';
                    res += temp;
                    temp = "";
                }   
            }else{
                temp += s[i];
            }
        }
        if (!temp.empty()) { 
            reverse(temp.begin(), temp.end());
            if (!res.empty()) res += ' ';
            res += temp;
        }
        return res;
    }
};