class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<char, int>> pq;
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                pq.push({(char)('a' + i), freq[i]});
            }
        }

        string result;

        while(!pq.empty()){
            auto [currChar, currCount] = pq.top();
            pq.pop();

            int toAdd = min(repeatLimit, currCount);
            result.append(toAdd, currChar);
            currCount -= toAdd;

            if (currCount > 0) {
                if (pq.empty()) break;

                auto [nextChar, nextCount] = pq.top();
                pq.pop();
                result.push_back(nextChar);
                nextCount--;

                if (nextCount > 0) {
                    pq.push({nextChar, nextCount});
                }

                pq.push({currChar, currCount});
            }
        }
        return result;
    }
};