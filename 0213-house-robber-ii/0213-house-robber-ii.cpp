class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);

        for(int i=2; i<nums.size()-1; i++){
            int curr = max(nums[i]+prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        int pre2 = nums[1];
        int pre1 = max(nums[1],nums[2]);

        for(int i=3; i<nums.size(); i++){
            int curr = max(nums[i]+pre2,pre1);
            pre2 = pre1;
            pre1 = curr;
        }
        
        return max(prev1,pre1);
    }
};