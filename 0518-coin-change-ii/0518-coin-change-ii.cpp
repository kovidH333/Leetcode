class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);;
        prev[0] = 1;

        for (int ind = 0; ind < coins.size(); ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                long notTake = prev[tar];
                long take = 0;
                if (coins[ind] <= tar) {
                    take = curr[tar - coins[ind]] ;
                } 
                curr[tar] = int(take + notTake);
            }
            prev = curr;
        }
        return prev[amount];
    }
};