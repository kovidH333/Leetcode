// class Solution {
// public:
//     string repeatLimitedString(string s, int repeatLimit) {
        
//         vector<int> freq(26, 0);
//         for (char c : s) {
//             freq[c - 'a']++;
//         }

//         priority_queue<pair<char, int>> pq;

//         for (int i = 0; i < 26; ++i) {
//             if (freq[i] > 0) {
//                 pq.push({(char)('a' + i), freq[i]});
//             }
//         }

//         string result;

//         while(!pq.empty()){
//             auto [currChar, currCount] = pq.top();
//             pq.pop();

//             int toAdd = min(repeatLimit, currCount);
//             result.append(toAdd, currChar);
//             currCount -= toAdd;

//             if (currCount > 0) {
//                 if (pq.empty()) break;

//                 auto [nextChar, nextCount] = pq.top();
//                 pq.pop();
//                 result.push_back(nextChar);
//                 nextCount--;

//                 if (nextCount > 0) {
//                     pq.push({nextChar, nextCount});
//                 }

//                 pq.push({currChar, currCount});
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int, greater<char>> freq; // Ordered map in descending order
        for (char ch : s) {
            freq[ch]++;
        }

        string result = "";

        while (!freq.empty()) {
            auto it = freq.begin(); // Largest available character
            char currentChar = it->first;
            int count = it->second;

            int useCount = min(count, repeatLimit); // Use up to repeatLimit
            result.append(useCount, currentChar);  // Append character to result
            freq[currentChar] -= useCount;         // Decrease frequency

            if (freq[currentChar] == 0) {
                freq.erase(currentChar);
            }
            int tempcn= freq[currentChar];
            char temp = currentChar;
            freq.erase(currentChar);

            if (tempcn>0 && !freq.empty()) {
                auto nextIt = freq.begin(); 
                char nextChar = nextIt->first;
                result += nextChar;        // Add the next largest character
                freq[nextChar]--;          // Decrease frequency
                freq[temp] = tempcn;
                // Remove the character if exhausted
                if (freq[nextChar] == 0) {
                    freq.erase(nextChar);
                }
            } 
            else if (useCount == repeatLimit && freq.empty()) {
                break; // No more characters to use
            }
        }

        return result;
    }
};