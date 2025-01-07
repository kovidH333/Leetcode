class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(2,0);
        dp[0] = dp[1] = 0; //base case

        for(int i=prices.size()-1; i<=prices.size(); i--){
            for(int buy=0; buy<2; buy++){
                if(buy){
                    dp[buy] = max(-prices[i]+dp[0], dp[1]);
                }else{
                    dp[buy] = max(prices[i]+dp[1]-fee, dp[0]);
                }
            }
        }
        return dp[1];
    }
};