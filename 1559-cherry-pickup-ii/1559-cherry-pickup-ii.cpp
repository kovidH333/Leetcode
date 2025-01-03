class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize the DP array
        vector<vector<int>> prev(n, vector<int>(n, -1e9));
        prev[0][n - 1] = grid[0][0] + (n > 1 ? grid[0][n - 1] : 0);

        for (int i = 1; i < m; i++) {
            vector<vector<int>> temp(n, vector<int>(n, -1e9));

            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    int max_cherries = -1e9;

                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int prev_j1 = j1 + dj1;
                            int prev_j2 = j2 + dj2;

                            if (prev_j1 >= 0 && prev_j1 < n && prev_j2 >= 0 && prev_j2 < n) {
                                max_cherries = max(max_cherries, prev[prev_j1][prev_j2]);
                            }
                        }
                    }

                    if (max_cherries != -1e9) {
                        temp[j1][j2] = max_cherries + grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    }
                }
            }

            prev = temp;
        }

        // Get the result from the last row
        int max_cherries = 0;
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                max_cherries = max(max_cherries, prev[j1][j2]);
            }
        }

        return max_cherries;
    }
};
