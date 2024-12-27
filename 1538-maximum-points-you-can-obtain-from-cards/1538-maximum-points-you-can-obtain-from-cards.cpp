class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0;
        int r = n-k-1;
        int sum = 0;
        for(int i=l; i<r+1; i++){
            sum += cardPoints[i];
        }
        int mini = sum;

        int tot_sum = 0;
        for(int i=0; i<n; i++){
            tot_sum += cardPoints[i];
        }

        while(r<n-1){
            sum = sum - cardPoints[l];
            l++;
            r++;
            sum = sum + cardPoints[r];
            mini = min(mini,sum);
        }

        return tot_sum - mini;
    }
};