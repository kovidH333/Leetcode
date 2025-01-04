class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size()-1;
        int n = s.size()-1;
        int ans = 0;

        while(m>=0 && n>=0){
            if(s[n] >= g[m]){
                n--;
                m--;
                ans++;
            }else{
                m--;
            }
        }
        return ans;
    }
};