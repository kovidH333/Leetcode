class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,INT_MAX);
        prev[0] = triangle[0][0];

        for(int i=1; i<n; i++){
            vector<int> temp(n,INT_MAX);
            for(int j=0; j<=i; j++){
                if(j>0) temp[j] = triangle[i][j]+ min(prev[j],prev[j-1]);
                else temp[j] = triangle[i][j]+ prev[j];
            }
            prev = temp;
        }
        int ans = prev[0];
        for(int i=1; i<n; i++){
            ans = min(ans,prev[i]);
        }
        return ans;

    }
};