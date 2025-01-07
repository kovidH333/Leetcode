class Solution {
public:
    int substr(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<int> prev(n+1,0),curr(n+1,0);
        int ans=0;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                    ans = max(ans,curr[j]);
                }else curr[j]=0;
            }
            prev = curr;
        }
        
        return ans;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        vector<int> visited(words.size(),0);
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(substr(words[i],words[j]) == min(words[i].size(),words[j].size())){
                       if(words[i].size() >= words[j].size()){
                        if(visited[j] == 0){
                            res.push_back(words[j]);
                            visited[j]=1;
                        }
                       }
                       else{
                        if(visited[i] == 0){
                            res.push_back(words[i]);
                            visited[i]=1;
                        }
                       } 
                }
            }
        }
        return res;
    }
};