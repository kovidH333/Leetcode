class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ahead1(2,0),ahead2(2,0),curr(2,0);

        for(int i=prices.size()-1; i<=prices.size(); i--){
            for(int buy=0; buy<2; buy++){
                if(buy){
                    curr[buy] = max(-prices[i]+ahead1[0], ahead1[1]);
                }else{
                    curr[buy] = max(prices[i]+ahead2[1], ahead1[0]);
                }
            }
            ahead2 = ahead1;
            ahead1 = curr;
        }
        return ahead1[1];
    }
};