class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum - target) % 2 != 0 || totalSum < abs(target)) {
            return 0;
        }

        int S1 = (totalSum - target) / 2;

        vector<int> prev(S1 + 1, 0), curr(S1 + 1, 0);
        prev[0] = 1; 

        for (int ind=0; ind<nums.size(); ind++) {
            for (int tar = 0; tar<=S1; tar++) {
                int nonpick = prev[tar];
                int pick = 0;
                if(nums[ind]<=tar) pick = prev[tar-nums[ind]];
                curr[tar] = pick + nonpick;
            }
            prev = curr;
        }

        return prev[S1];
    }
};