class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ahead(2,0), curr(2,0);
        ahead[0] = ahead[1] = 0; //base case

        for(int i=prices.size()-1; i<=prices.size(); i--){
            for(int buy=0; buy<2; buy++){
                if(buy){
                    curr[buy] = max(-prices[i]+ahead[0], ahead[1]);
                }else{
                    curr[buy] = max(prices[i]+ahead[1], ahead[0]);
                }
            }
            ahead = curr;
        }
        return ahead[1];
    }
};