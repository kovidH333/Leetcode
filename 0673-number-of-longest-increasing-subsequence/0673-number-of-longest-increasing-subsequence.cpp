class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), cnt(nums.size(),1);
        int maxi = 1;
        int res = 0;

        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(dp[i] == 1+dp[j]){
                        cnt[i] += cnt[j];
                    }else if(dp[i]<1+dp[j]){
                        dp[i] = 1+dp[j];
                        cnt[i] = cnt[j];
                    }
                }
            }
            maxi = max(maxi,dp[i]);
        }

        for(int i=0; i<nums.size(); i++){
            if(dp[i]==maxi){
                res += cnt[i];
            }
        }
        return res;
    }
};