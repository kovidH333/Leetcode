// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();

//         vector<int> row(m,0);
//         vector<int> col(n,0);

//         unordered_map<int, pair<int, int>> posMap;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 posMap[mat[i][j]] = {i, j}; 
//             }
//         }

//         for(int t=0; t<arr.size(); t++){
//             row[posMap[arr[t]].first]++;
//             col[posMap[arr[t]].second]++;
//             if(row[posMap[arr[t]].first]==n||col[posMap[arr[t]].second]==m){
//                 return t;
//             }
//         }
//         return m*n-max(m,n);
//     }
// };


//Mind blowing solution
// Instead of checking each row and column after every iteration, we will check for all rows and columns, at what index in the array arr, they will be painted completely, i.e., the element having largest index in array arr. Smallest of those will be the required answer.

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size();
        int numCols = mat[0].size();

        unordered_map<int, int> numToIndex;
        for (int i = 0; i < arr.size(); i++) {
            numToIndex[arr[i]] = i;
        }

        int result = INT_MAX;

        for (int row = 0; row < numRows; row++) {
            int lastElementIndex = INT_MIN;
            for (int col = 0; col < numCols; col++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            result = min(result, lastElementIndex);
        }

        for (int col = 0; col < numCols; col++) {
            int lastElementIndex = INT_MIN;
            for (int row = 0; row < numRows; row++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            result = min(result, lastElementIndex);
        }

        return result;


    }
};

