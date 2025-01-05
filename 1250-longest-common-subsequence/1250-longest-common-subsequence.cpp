class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> prev(n+1,0), curr(n+1,0);
        for(int i=0; i<=n; i++) prev[i]=0;

        for(int ind1=1; ind1<=m; ind1++){
            for(int ind2=1; ind2<=n; ind2++){
                if(text1[ind1-1]==text2[ind2-1]) curr[ind2]= 1+ prev[ind2-1];
                else curr[ind2] = 0 + max(prev[ind2],curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};