class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long scr = 0;
        vector<bool> processed(n, false); // Track processed elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // Push all elements into the heap
        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i], i});
        }

        while (!minHeap.empty()) {
            auto [val, idx] = minHeap.top();
            minHeap.pop();

            if (processed[idx]) continue;

            scr += val;
            processed[idx] = true;

            if (idx - 1 >= 0) processed[idx - 1] = true;
            if (idx + 1 < n) processed[idx + 1] = true;
        }

        return scr;
    }
};
