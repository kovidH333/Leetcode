class Solution {
public:

    int func(vector<int>& nums, int goal){
        int left = 0;
        int sum = 0;
        int count = 0;

        for(int right=0; right<nums.size(); right++){
            sum += nums[right];
            if(goal<0) return 0;

            while(sum>goal){
                sum -= nums[left];
                left++;
            }
            count += right-left+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return func(nums,goal)-func(nums,goal-1);
        
    }
};