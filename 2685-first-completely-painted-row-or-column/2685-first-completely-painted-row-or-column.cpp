class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m,0);
        vector<int> col(n,0);

        unordered_map<int, pair<int, int>> posMap;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                posMap[mat[i][j]] = {i, j}; 
            }
        }

        for(int t=0; t<arr.size(); t++){
            row[posMap[arr[t]].first]++;
            col[posMap[arr[t]].second]++;
            if(row[posMap[arr[t]].first]==n||col[posMap[arr[t]].second]==m){
                return t;
            }
        }
        return m*n-max(m,n);
    }
};
