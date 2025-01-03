class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        int ans = 0;
        vector<long> dp(nums.size(),0);
        dp[0] = nums[0];
        if(nums[0] >= sum-nums[0]) ans++;
        for(int i=1; i<nums.size()-1; i++){
            dp[i] = dp[i-1]+nums[i];
            if(dp[i] >= sum-dp[i]) ans++;
        }
        return ans;
    }
};