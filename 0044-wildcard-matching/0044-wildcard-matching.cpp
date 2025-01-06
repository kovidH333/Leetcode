class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<bool> prev(m+1,0), curr(m+1,0);
        prev[0] = 1; //base case

        for(int j=1; j<=n; j++){
            curr[0] = (p[j - 1] == '*' && prev[0]);
            for(int i=1; i<=m; i++){
                if(p[j-1] == s[i-1]){
                    curr[i] = prev[i-1];
                }else if(p[j-1]=='*'){
                    curr[i] = prev[i] || curr[i-1];
                }else if(p[j-1]=='?'){
                    curr[i] = prev[i-1];
                }else{
                    curr[i] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};