class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int lastindex = 0;
        vector<int> dp(n,1), hash(n,0);
        sort(nums.begin(), nums.end());
        hash[0]=0;
        for(int i=0; i<n; i++){
            hash[i]=i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j] > dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }

        vector<int> res;
        res.push_back(nums[lastindex]);
        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            res.push_back(nums[lastindex]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};