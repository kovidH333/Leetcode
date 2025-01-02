class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));

        dp[0][0] = grid[0][0];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int x = INT_MAX;
                int y = INT_MAX;
                if(i>0) x = dp[i-1][j];
                if(j>0) y = dp[i][j-1];

                if(i>0 || j>0) dp[i][j] = grid[i][j] + min(x,y);
            }
        }

        return dp[m-1][n-1];
    }
};