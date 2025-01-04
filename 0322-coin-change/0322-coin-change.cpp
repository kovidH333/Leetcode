class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount + 1, INT_MAX), curr(amount + 1, INT_MAX);;
        prev[0] = 0;

        for (int ind = 0; ind < coins.size(); ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                int notTake = prev[tar];
                int take = INT_MAX;
                if (coins[ind] <= tar) {
                    if (curr[tar - coins[ind]] != INT_MAX) {
                        take = curr[tar - coins[ind]] + 1;
                    }
                } 
                curr[tar] = min(take, notTake);
            }
            prev = curr;
        }

        if (prev[amount] == INT_MAX) return -1;
        return prev[amount];
    }
};
