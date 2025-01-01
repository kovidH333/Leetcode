class Solution {
public:
    int maxScore(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0') cnt0++;
            if(s[i]=='1') cnt1++;
        }
        int score = cnt1;
        if(s[0]=='0') score++;
        if(s[0]=='1') score--;
        int max_score = score;
        for(int i=1; i<s.size()-1; i++){
            if(s[i]=='0') score++;
            if(s[i]=='1') score--;
            max_score = max(max_score,score);
        }
        return max_score;
    }
};