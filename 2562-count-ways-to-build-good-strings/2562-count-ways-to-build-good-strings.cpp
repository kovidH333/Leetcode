class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int MOD = 1e9 + 7;
        int res = 0;
        vector<int> dp(high+1,0);
        dp[0] = 1;
        for(int i=1; i<=high; i++){
            if(i-zero >= 0) dp[i] = (dp[i] + dp[i-zero])%MOD;
            if(i-one >= 0) dp[i] = (dp[i] + dp[i-one])%MOD;
            if(i>=low) res = (res + dp[i])%MOD;
        }

        return res;
    }
};