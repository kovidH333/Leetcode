class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,INT_MAX);
        for(int i=0; i<n; i++){
            prev[i]=matrix[0][i];
        }

        for(int i=1; i<n; i++){
            vector<int> temp(n,INT_MAX);
            for(int j=0; j<n; j++){
                int x = INT_MAX;
                int y = INT_MAX;
                if(j>0) x = prev[j-1];
                if(j<n-1) y = prev[j+1];
                temp[j] = matrix[i][j] + min({prev[j],x,y});
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