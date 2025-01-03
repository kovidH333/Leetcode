// class Solution {
// public:
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
//         int n = words.size();
//         vector<int> Prefix(n + 1, 0);
//         unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; 
//         for (int i = 0; i < n; i++) {
//             Prefix[i + 1] = Prefix[i];
//             if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
//                 Prefix[i + 1]++;  
//             }
//         }
//         vector<int> ANS; 
//         for (auto& query : queries) {
//             int L = query[0], R = query[1];  
//             ANS.push_back(Prefix[R + 1] - Prefix[L]);  
//         }

//         return ANS;  
//     }
// };

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>good(n,0);

        for(int i=0; i<n; i++){
            int len = words[i].size();
            if(i>0) good[i]=good[i-1];
            if(words[i][0]=='a'||words[i][0]=='e'||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u'){
                if(words[i][len-1]=='a'||words[i][len-1]=='e'||words[i][len-1]=='i'||words[i][len-1]=='o'||words[i][len-1]=='u'){
                    good[i]++;
                }
            }
        }

        int m = queries.size();
        vector<int> ans(m,0);

        for(int j=0; j<m; j++){
            int L = queries[j][0];
            int R = queries[j][1];
            if(L==0) ans[j] = good[R];
            else ans[j] = good[R] - good[L-1];
        }

        return ans;

    }
};