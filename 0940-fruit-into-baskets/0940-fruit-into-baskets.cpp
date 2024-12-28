class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxlen = 0;
        unordered_map<int,int> unq;

        for(int right=0; right<fruits.size(); right++){
            unq[fruits[right]]++;
            if(unq.size()>2){
                unq[fruits[left]]--;
                if(unq[fruits[left]]==0) unq.erase(fruits[left]);
                left++;
            }
            if(unq.size()<=2) maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};