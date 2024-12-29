class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> windowsums(n - k + 1, 0);
        int l = 0, r = 0, sum = 0;

        while(r < k){
            sum += nums[r];
            r++;
        }
        windowsums[0] = sum;

        while(r < n){
            sum += nums[r];
            sum -= nums[l];
            r++;
            l++;
            windowsums[l] = sum;
        }

        // Compute leftMax
        vector<int> leftMax(n - k + 1, 0);
        int maxIdx = 0;
        for (int i = 0; i < windowsums.size(); i++) {
            if (windowsums[i] > windowsums[maxIdx]) {
                maxIdx = i;
            }
            leftMax[i] = maxIdx;
        }

        // Compute rightMax
        vector<int> rightMax(n - k + 1, 0);
        maxIdx = n - k;
        for (int i = n - k; i >= 0; i--) {
            if (windowsums[i] >= windowsums[maxIdx]) {
                maxIdx = i;
            }
            rightMax[i] = maxIdx;
        }

        // Find the maximum sum using the middle subarray
        vector<int> result(3, 0);
        int maxSum = 0;
        for (int j = k; j <= n - 2 * k; j++) {
            int left = leftMax[j - k];
            int right = rightMax[j + k];
            int totalSum = windowsums[left] + windowsums[j] + windowsums[right];

            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {left, j, right};
            }
        }

        return result;
    }
};
