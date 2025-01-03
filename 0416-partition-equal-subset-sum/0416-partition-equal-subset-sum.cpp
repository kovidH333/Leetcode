class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        int target = 0;
        if(sum % 2 == 0) target = sum/2;
        else return false;

        vector<bool> prev(target+1,0), curr(target+1,0);
        prev[0] = true;

        if (nums[0] <= target) {
            prev[nums[0]] = true;
        }

        for (int ind = 1; ind < nums.size(); ind++) { 
            for (int tar = 0; tar <= target; tar++) {
                bool notTake = prev[tar];
                bool take = false;
                if (tar >= nums[ind]) {
                    take = prev[tar - nums[ind]];
                }

                curr[tar] = take || notTake;
            }
            prev = curr; 
        }

        return prev[target];
        
    }
};