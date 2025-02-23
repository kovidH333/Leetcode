class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int>(3, 0)), curr(2,vector<int>(3, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy){
                    curr[buy][cap] = max(-prices[i] + ahead[0][cap], ahead[1][cap]);
                    }else{
                        curr[buy][cap] = max(prices[i] + ahead[1][cap-1], ahead[0][cap]);
                    }

                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};