class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        int left = 0;
        int maxlen = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                q.push(right);
            }

            if (q.size() > k) {
                left = q.front() + 1;
                q.pop();
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};