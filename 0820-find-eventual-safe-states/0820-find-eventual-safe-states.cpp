class Solution {
public:
    bool func(int i, vector<int>& dp, vector<vector<int>>& graph){
        if(dp[i]>0) return dp[i] == 2;
        dp[i] = 1;
        for(int j=0; j<graph[i].size(); j++){
            if(dp[graph[i][j]] == 1 || !func(graph[i][j],dp,graph)){
                return false;
            }
        }
        dp[i] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> dp(graph.size(),0);
        vector<int> res;
        for(int i=0; i<graph.size(); i++){
            if(func(i,dp,graph)) res.push_back(i);
        }
        return res;
    }
};