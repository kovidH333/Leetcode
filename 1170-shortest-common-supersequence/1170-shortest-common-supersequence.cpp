class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int ind1=1; ind1<=m; ind1++){
            for(int ind2=1; ind2<=n; ind2++){
                if(str1[ind1-1]==str2[ind2-1]) dp[ind1][ind2]= 1+ dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        int len = dp[m][n];
        vector<char> lcs(len,'$');
        int i=m,j=n;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                lcs[len-1] = str1[i-1];
                len--;
                i--;
                j--;
            }else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }

        len = lcs.size();
        i=0;
        j=0;
        int k=0;
        vector<char> ansr;

        while(k<len){
            if(str1[i]==lcs[k]){
                if(str2[j]==lcs[k]){
                    ansr.push_back(lcs[k]);
                    i++;
                    j++;
                    k++;
                }else{
                    ansr.push_back(str2[j]);
                    j++;
                }
            }else{
                if(str2[j]==lcs[k]){
                    ansr.push_back(str1[i]);
                    i++;
                }else{
                    ansr.push_back(str2[j]);
                    ansr.push_back(str1[i]);
                    i++;
                    j++;
                }
            }
        }
        while (i < m) {
            ansr.push_back(str1[i]);
            i++;
        }
        while (j < n) {
            ansr.push_back(str2[j]);
            j++;
        }
        return string(ansr.begin(), ansr.end());

    }
};