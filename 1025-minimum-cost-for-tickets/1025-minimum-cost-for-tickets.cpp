class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,0);
        dp[0] = min({costs[0], costs[1], costs[2]});
        
        for(int i=1; i<days.size(); i++){
            int x = dp[i-1]+costs[0];
            int j = i;
            while(j>=0){
                if(days[i]-days[j] > 6) break;
                j--;
            }
            int y = costs[1];
            if(j>=0) y += dp[j];
            
            int k = i;
            while(k>=0){
                if(days[i]-days[k] > 29) break;
                k--;
            }
            int z = costs[2];
            if(k>=0) z += dp[k];

            dp[i] = min({x,y,z});
        }
        return dp[n-1];
    }
};