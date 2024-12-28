class Solution {
public:
    int func(vector<int>& nums, int k){
        int l = 0;
        int cnt = 0;
        unordered_map<int,int> hashmap;
        int typecnt = 0;

        for(int r=0; r<nums.size(); r++){
            if(hashmap.find(nums[r]) == hashmap.end()) typecnt++;
            hashmap[nums[r]]++;

            while(typecnt > k){
                hashmap[nums[l]]--;
                if(hashmap[nums[l]] == 0){
                    hashmap.erase(nums[l]);
                    typecnt--;
                } 
                l++;
            }
            cnt += r-l+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};